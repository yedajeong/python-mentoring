#include <iostream>
using namespace std;

//01
int sum(int x, int y) { return x + y; }
int mult(int x, int y) { return x * y; }
int evaluate(int(*f)(int, int), int x, int y) {
	return f(x, y);
}
int main() {
	cout << evaluate(&sum, 2, 3) << endl;
	cout << evaluate(&mult, 2, 3) << endl;

	[](int x, int y)->int { return x + y; };
	cout << evaluate([](int x, int y)->int { return x + y; }, 20, 30) << endl;

	[](int x, int y) {return x * y; };
	cout << evaluate([](int x, int y) {return x * y; }, 20, 30) << endl;

	[](int x, int y) { cout << x << ", " << y <<endl; } (20, 30);

	auto f = [](int x, int y) { return x - y; };
	cout << f(1000, 2000) << endl;

	return 0;
}
