#include  <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

void get_command(string& command);
void get_size(int& size);
int** gen_matrix(int& size);
void swap(int* a, int* b);
void sort_array(int*& arr, int size);
void sort_matrix_row(int**& matrix, int size);
void print_matrix(int** matrix, int size);
void save_matrix(int**& matrix, int size);
void free_matrix(int**& matrix, int size);

int main() {
	string command;
	int** matrix = NULL;
	int size = 0;
	while (1) {
		get_command(command);
		if (command == "1") {
			get_size(size);
			matrix = gen_matrix(size);
		}
		else if (command == "2") {
			print_matrix(matrix, size);
		}
		else if (command == "3") {
			sort_matrix_row(matrix, size);
		}
		else if (command == "4") {
			save_matrix(matrix, size);
		}
		else if (command == "0") {
			free_matrix(matrix, size);
			cout << "Exit the program.." << endl;
			exit(104);
		}
		else {
			cout << "Wrong command" << endl << endl;
		}
	}

	return 0;
}

void get_command(string& _command) {
	cout << "1. Generate matrix" << endl
		<< "2. Print matrix" << endl
		<< "3. Sort matrix" << endl
		<< "4. Save matrix" << endl
		<< "0. Exit program" << endl << ">>";
	cin >> _command;
}

void get_size(int& size) {
	cout << "Enter the size in (size x size): ";
	cin >> size;
	cout << endl;
}

int** gen_matrix(int& size) {
	int** matrix = new int*[size];
	for (int i = 0; i < size; i++)
		matrix[i] = new int[size];

	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++)
			matrix[row][col] = rand() % 101;
	}

	return matrix;
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sort_array(int*& arr, int size) {
	for (int i = 0; i < size-1; i++) {
		for (int j = i+1; j < size; j++) {
			if (arr[j] < arr[j - 1])
				swap(arr[j], arr[j - 1]);
		}
	}
}

void sort_matrix_row(int**& matrix, int size) {
	for (int row = 0; row < size; row++)
		sort_array(matrix[row], size);

	cout << "Completed" << endl << endl;
}
void print_matrix(int** matrix, int size) {
	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++)
			cout << setw(4) << matrix[row][col];
		cout << endl;
	}
	cout << endl;
}

void save_matrix(int**& matrix, int size) {
	ofstream fout("matrix.txt");
	fout << size << endl;
	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++) {
			fout << setw(4) << matrix[row][col];
		}
		fout << endl;
	}
	cout << "Saved" << endl << endl;
}

void free_matrix(int**& matrix, int size) {
	for (int i = 0; i < size; i++)
		delete matrix[i];
	delete matrix;
}