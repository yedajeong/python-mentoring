#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//ÀÀ¿ë 03
int* make_arr(int size) {
	int *a = new int[size];
	for (int i = 0; i < size; i++) {
		int elem = rand() % size + 1;
		a[i] = elem;
	}
	return a;
}

void print_arr(int *a, int size) {
	cout << "\n[ Array ]" << endl;
	for (int i = 0; i < size; i++)
		cout << a[i] << " ";
	cout << endl;
}

bool find_dup(int *a, int size) {
	for (int i = 0; i < size; i++) {
		int num = a[i];
		for (int j = 0; j < size; j++) {
			if (num == a[j]) {
				if (i == j)
					continue;
				else
					return true;
			}
				
		}
	}
	return false;
}

int main() {
	int n;
	do {
		cout << "Please enter a number : ";
		cin >> n;

		if (n < 2) {
			cout << "Wrong number!";
			exit(EXIT_FAILURE);
		}

		int size = n / 2;

		cout << "Size of random array : " << size;

		int *arr = make_arr(size);
		print_arr(arr, size);
		if (find_dup(arr, size))
			cout << "Duplicates found\n";
		else
			cout << "Duplicates not found\n";

		cout << endl;
	} while (n >= 2);

	return 0;
}