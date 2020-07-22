#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

//07
int main() {
	double x, y;
	cout << "x : ";
	cin >> x;
	cout << "y : ";
	cin >> y;

	cout << "Rounding up number of " << x << ":" << ceil(x) << endl;
	cout << "Rounding down number of " << x << ":" << floor(x) << endl;
	cout << "Rounding number of " << x << ":" << round(x) << endl;
	cout << "Maximum number between " << x << " and " << y << ":" << max(x, y) << endl;
	cout << y << "-th root of" << x << ":" << pow(x, y) << endl;
	cout << "|" << x << "-" << y << "| :" << fabs(x-y) << endl;
}