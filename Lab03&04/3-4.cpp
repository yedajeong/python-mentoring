#include <iostream>
using namespace std;

//04
void applePrice(int a = 1000) { // default argument
	cout << "Price of an apple is " << a << endl;
}

int main() {
	applePrice(1500);
	applePrice(500);
	applePrice(1000);
	applePrice(); // �Լ��� �� �Ҵ����� �ʾƵ� n=1000�� �ڵ����� �Ҵ��

	return 0;
}