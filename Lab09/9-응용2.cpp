#include <iostream>
#include <iomanip>
using namespace std;

//ÀÀ¿ë 02
int* make_arr(int n) {
	int *a = new int[n];
	int elem = 1;
	for (int i = 0; i < n; i++) {
		a[i] = elem;
		elem += 2;
	}
	return a;
}

void print_arr(int *a, int n) {
	cout << "\nOdd Number Array : " << endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

int sum_arr(int *a, int n) {
	int s = 0;
	for (int i = 0; i < n; i++) {
		s += *a;
		a++;
	}
	return s;
}

int main() {
	int n;
	cout << "Enter a number : ";
	cin >> n;

	int *arr = make_arr(n);
	print_arr(arr, n);

	int sum = sum_arr(arr, n);
	cout << "\nSum of the array : " << sum << endl;

	delete[] arr;
	return 0;
}