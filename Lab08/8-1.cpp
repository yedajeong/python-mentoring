#include <iostream>
using namespace std;

//01
// int &x = a; int &y = b; pass by reference
// int *x = &a; int *y = &b; pass by address
void swap(int *x, int *y) { 
	int temp = *x;
	*x = *y;
	*y = temp;
}

int main() {
	int a = 10, b = 20;
	cout << a << " , " << b << endl;
	swap(a, b);
	cout << a << " , " << b << endl;

	return 0;
}
