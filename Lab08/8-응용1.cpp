#include <iostream>
using namespace std;

//���� 01
void mySqure(int *p) {
	cout << "������> " << (*p * *p);
}
int main() {
	int input;
	cout << "input> ";
	cin >> input;
	int *inputP = &input;

	mySqure(inputP);

	return 0;
}