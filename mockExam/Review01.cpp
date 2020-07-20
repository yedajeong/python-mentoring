#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

void get_command(string &command) {
	cout << "1. Generate matrix\n" << "2. Print matrix\n" << "3. Sort matrix\n"
		<< "4. Save matrix\n" << "0. Exit program\n" << ">>";
	cin >> command;
}
void get_size(int &size) {
	cout << "Enter the size in (size x size): ";
	cin >> size;
	cout << endl;
}
int** gen_matrix(int &size) {
	int** matrix = new int*[size];
	for (int i = 0; i < size; i++) {
		matrix[i] = new int[size];
	}
	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++) {
			matrix[row][col] = rand() % 101;
		}
	}
	return matrix;
}
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void sort_array(int* &row, int size) {
	for (int i = 0; i < (size - 1); i++) {
		for (int j = (i + 1); j < size; j++) {
			if (row[j] < row[j - 1])
				swap(row[j], row[j - 1]);
			else
				continue;
		}
	}
}
void sort_matrix_row(int** &matrix, int size) {
	for (int i = 0; i < size; i++)
		sort_array(matrix[i], size);
	cout << "Completed" << endl << endl;
}
void print_matrix(int** matrix, int size) {
	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++)
			cout << setw(4) << matrix[row][col];
		cout << endl;
	}
}
void save_matrix(int** &matrix, int size) {
	ofstream fout("matrix.txt");
	fout << size << endl;
	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++)
			fout << setw(4) << matrix[row][col];
		fout << endl;
	}
	cout << "Saved" << endl << endl;
}
void free_matrix(int** &matrix, int size) {
	for (int i = 0; i < size; i++)
		delete matrix[i];
	delete matrix;
}

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