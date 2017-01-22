#include<iostream>
#include<thread>
#include<fstream>
#include<vector>

using namespace std;

/*int am_threads = 0;

const int max_n = 40;

void swap(int& a, int& b) {
	int	temp = a;
	a = b;
	b = temp;
}

void comp(int& a, int& b) {
	if (a > b) swap(a, b);
}
void comp_mas(vector<int> & a, int i, int j, int size_part) {
	if (a.size() % size_part != 0 || i < 0 || i > j || i > a.size() - 1 || j < 0 || j > a.size() - 1 || size_part < 1) return;
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
		first.push_back(min);
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
		second.insert(second.begin(), max);
		temp.erase(temp.begin() + ind_max);
	}
	for (int k = 0; k < size_part; k++) {
		a[size_part * i + k] = first[k];
		a[size_part * j + k] = second[k];
	}
}

void parallel(vector<int>& a, int d, int p, int r, int length, int size_part) {
	thread thread_arr[max_n];
	int counter = 0;
	am_threads = 0;
	for (int i = 0; i < length - d; ++i) {
		if ((i & p) == r) {
			if (size_part != 1) {
				thread_arr[counter] = thread(comp_mas, ref(a), i, i + d, size_part);
				thread_arr[counter].join();
				++counter;
				am_threads++;
			}
			else
			{
				thread_arr[counter] = thread(comp, ref(a[i]), ref(a[i + d]));
				thread_arr[counter].join();
				++counter;
			}

		}
	}
}

void oddeven_merge_sort(const int length, vector<int>& a, int size_part) {
	if (size_part * length != a.size()) return;
	int t = ceil(log2(length));
	int p = pow(2, t - 1);

	while (p > 0) {
		int q = pow(2, t - 1);
		int r = 0;
		int d = p;

		while (d > 0) {
			parallel(a, d, p, r, length, size_part);
			d = q - p;
			q /= 2;
			r = p;
		}
		p /= 2;
	}
}

//file structure
//size of testing massive
//testing massive
//result massive
//size_part length
void input(vector<int>& test_massive, char* file_name, vector<int>& res_mas, int& length, int& size_part) {
	ifstream input_file(file_name);
	char temp[10];
	int size1;
	input_file >> temp;
	size1 = atoi(temp);
	for (int k = 0; k < size1; k++) {
		input_file >> temp;
		test_massive.push_back(atoi(temp));
	}
	for (int k = 0; k < size1; k++) {
		input_file >> temp;
		res_mas.push_back(atoi(temp));
	}
	input_file >> temp;
	size_part = atoi(temp);
	input_file >> temp;
	length = atoi(temp);
	input_file.close();
}

int main() {
	vector<int> test_massive;
	vector<int> result_massive;
	int length, size_part;
	vector<char*> test_files;
	char* name = "test_sort1.txt";
	test_files.push_back(name);
	name = "test_sort2.txt";
	test_files.push_back(name);
	name = "test_sort3.txt";
	test_files.push_back(name);
	for (int i = 0; i < test_files.size(); i++) {
		test_massive.resize(0);
		result_massive.resize(0);
		input(test_massive, test_files[i], result_massive, length,size_part);
		cout << "Testing massive:\n";
		for (int k = 0; k < test_massive.size(); k++)
			cout << test_massive[k] << " ";
		oddeven_merge_sort(length, test_massive, size_part);
		cout << "\nResult massive:\n";
		for (int k = 0; k < test_massive.size(); k++)
			cout << test_massive[k] << " ";
		cout << "\nCorrect result massive:\n";
		for (int k = 0; k < result_massive.size(); k++)
			cout << result_massive[k] << " ";
		if (test_massive == result_massive)
			cout << "\nTRUE\n";
		else
			cout << "\nFALSE\n";
	}
	system("pause");
}*/