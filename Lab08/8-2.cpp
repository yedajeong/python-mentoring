#include <iostream>
using namespace std;

//02
int sum(int x, int y) { return x + y; }
int mult(int x, int y) { return x * y; }
// 함수 fucn의 포인터와 파라미터 x, y를 받아와서 함수 func의 시행값을 리턴해주는 함수
int evaluate(int(*f)(int, int), int a, int b) {
	return f(a, b);
}

int main() {
	int(*func)(int, int);

	func = &sum; // sum 함수 주솟값 대입
	cout << func(10, 20) << endl; 

	func = &mult; // mult 함수 주솟값 대입
	cout << func(10, 20) << endl;
	cout << evaluate(&sum, 100, 200) << endl;
	cout << evaluate(&mult, 100, 200) << endl;

	return 0;
}