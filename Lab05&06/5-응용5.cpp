#include <iostream>
#include <cmath>
using namespace std;

//ÀÀ¿ë 05
int gcd(int a, int b);
int main() {
	int x, y;
	cout << "x = ";
	cin >> x;
	cout << "y = ";
	cin >> y;

	cout << "gcd(" << x << ", " << y << ") = " << gcd(x, y);
	return 0;
}

int gcd(int a, int b) {
	int c = abs(a - b);
	if (c != 0) {
		gcd(b, c);
	}
	else 
		return a;
}