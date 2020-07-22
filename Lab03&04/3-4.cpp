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
	applePrice(); // 함수에 값 할당하지 않아도 n=1000이 자동으로 할당됨

	return 0;
}