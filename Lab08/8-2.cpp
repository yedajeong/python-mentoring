#include <iostream>
using namespace std;

//02
int sum(int x, int y) { return x + y; }
int mult(int x, int y) { return x * y; }
// �Լ� fucn�� �����Ϳ� �Ķ���� x, y�� �޾ƿͼ� �Լ� func�� ���ప�� �������ִ� �Լ�
int evaluate(int(*f)(int, int), int a, int b) {
	return f(a, b);
}

int main() {
	int(*func)(int, int);

	func = &sum; // sum �Լ� �ּڰ� ����
	cout << func(10, 20) << endl; 

	func = &mult; // mult �Լ� �ּڰ� ����
	cout << func(10, 20) << endl;
	cout << evaluate(&sum, 100, 200) << endl;
	cout << evaluate(&mult, 100, 200) << endl;

	return 0;
}