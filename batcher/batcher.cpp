#include<iostream>
#include<thread> 
#include<vector>
#include<fstream>
#include<conio.h>

using namespace std;

int am_threads = 0;

const int max_n = 40;

void oddeven_merge_sort(const int length, vector<int>&, int);
void parallel(vector<int>& a, int d, int p, int r, int length, int size_part);
void comp(int& a, int& b);
void comp_mas(vector<int> & a, int i, int j, int size_part);
void input(vector<int>& massive);

int main() {
	do {
		system("cls");
		vector<int> mas;
		input(mas);
		cout << "Enter k\nk=";
		int k;
		cin >> k;
		int rest;
		if (rest = mas.size() % (2 * k)) { //adding zeros in the end of the massive in order to have 2*k equal parts
			for (int i = 0; i < 2 * k - rest; i++)
				mas.push_back(0);
		}
		int size_part = (mas.size() + 2*k - rest) / (2 * k);
		oddeven_merge_sort(2 * k, mas, size_part);
		if (rest) //cleaning zeros which we added before
			for (int i = 0; i < 2 * k - rest; i++)
				mas.erase(mas.begin());
		cout << endl;
		for (int i = 0; i < mas.size(); i++)
			cout << mas[i] << " ";
	} while (_getch() != 27);
}

void input(vector<int>& massive) { //downloading massive from file
	cout << "Enter the name of file" << endl;
	char file_name[25];
	while (true) {
		cin >> file_name;
		ifstream input_file(file_name);
		if (input_file.fail()) cerr << "Error! with opening file " << file_name << endl << "Enter the name of file" << endl;
		else { input_file.close(); break; }
	}
	ifstream input_file(file_name);
	char temp[10];
	while (!input_file.eof()) {
		input_file >> temp;
		massive.push_back(atoi(temp));
	}
	input_file.close();
}


void oddeven_merge_sort(const int length, vector<int>& a, int size_part) {//main sorting function
	if (size_part * length != a.size()) return;
	int t = ceil(log2(length));
	int p = pow(2, t - 1);

	while (p > 0) {
		int q = pow(2, t - 1);
		int r = 0;
		int d = p;

		while (d > 0) {
			parallel(a, d, p, r, length, size_part);//one step of sorting, where compares making independently
			//cout << "\nThreads amount = " << am_threads << endl;
			d = q - p;
			q /= 2;
			r = p;
		}
		p /= 2;
	}
}

void parallel(vector<int>& a, int d, int p, int r, int length, int size_part) {
	thread thread_arr[max_n];
	int counter = 0;
	am_threads = 0;
	for (int i = 0; i < length - d; ++i) {
		if ((i & p) == r) {
			if (size_part != 1) {//if we need compare massives
				thread_arr[counter] = thread(comp_mas, ref(a), i, i + d, size_part);
				thread_arr[counter].join();
				++counter;
				am_threads++;
			}
			else //if we need compare numbers
			{
				thread_arr[counter] = thread(comp, ref(a[i]), ref(a[i + d]));
				thread_arr[counter].join();
				++counter;
			}
			
		}
	}
}

void swap(int& a, int& b) {
	int	temp = a;
	a = b;
	b = temp;
}

void comp(int& a, int& b) {
	if (a > b) swap(a, b);
}

void comp_mas(vector<int> & a, int i, int j, int size_part) {
		if (a.size() % size_part != 0 || i < 0 || i > j || i > a.size()- 1 || j < 0 || j > a.size() - 1 || size_part < 1 ) return;
		vector<int> first, second;
		vector<int> temp(size_part * 2);
		for (int k = 0; k < size_part; k++) {
			temp[k] = a[size_part * i + k];
			temp[k + size_part] = a[size_part * j + k];
		}
		int ind_min, ind_max;
		int min, max;
		while (temp.size() > size_part) {
			ind_min = 0;
			min = temp[ind_min];
			for (int k = 0; k < temp.size(); k++) {
				if (temp[k] < min) {
					min = temp[k];
					ind_min = k;
				}
			}
			first.push_back(min); //first part should include sorting minimums of both parts
			temp.erase(temp.begin() + ind_min);
		}
		while (temp.size() > 0) {
			ind_max = 0;
			max = temp[ind_max];
			for (int k = 0; k < temp.size(); k++)
				if (temp[k] > max) {
					max = temp[k];
					ind_max = k;
				}
			second.insert(second.begin(), max);// second part should include sorting maximums of both parts
			temp.erase(temp.begin() + ind_max);
		}
		for (int k = 0; k < size_part; k++) {
			a[size_part * i + k] = first[k];
			a[size_part * j + k] = second[k];
		}
}

