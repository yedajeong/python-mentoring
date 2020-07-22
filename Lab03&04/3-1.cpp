#include <iostream>
using namespace std;

//01
int square(int n);

int main() {
	int x;
	x = 5;
	cout << square(5) << endl;

	return 0;
}

int square(int n) {
	return n * n;
}
