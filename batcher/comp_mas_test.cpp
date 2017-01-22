#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

/*void comp_mas(vector<int> & a, int i, int j, int size_part) {
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
//file structure:
//size of testing massive
//testing massive
//result massive
//i j size_part
void input(vector<int>& test_massive, char* file_name, vector<int>& res_mas, int& i, int& j, int& size_part) {
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
	i = atoi(temp);
	input_file >> temp;
	j = atoi(temp);
	input_file >> temp;
	size_part = atoi(temp);
	input_file.close();
}

int main() {
	vector<int> test_massive;
	vector<int> result_massive;
	int i, j, size_part;
	vector<char*> test_files;
	char* name = "test_comp1.txt";
	test_files.push_back(name);
	name = "test_comp2.txt";
	test_files.push_back(name);
	name = "test_comp3.txt";
	test_files.push_back(name);
	for (int c = 0; c < test_files.size(); c++) {
		test_massive.resize(0);
		result_massive.resize(0);
		input(test_massive, test_files[c], result_massive, i, j, size_part);
		cout << "Testing massive:\n";
		for (int k = 0; k < test_massive.size(); k++)
			cout << test_massive[k] << " ";
		comp_mas(test_massive, i, j, size_part);
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