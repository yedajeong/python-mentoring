#include <iostream>
#include <iomanip>
using namespace std;

//04-1
int main() {
	int num;

	while (true) {
		cout << "Enter the number (0, 10]: ";
		cin >> num;
		if (num <= 0 || num > 10) {
			continue;
		}
		else
			break;
	}
	cout << "Success!" << endl;
	return 0;
}

/*
//04-2
int main() {
	int input;
	do {
		cout << "Enter the number (0, 100]: ";
		cin >> input;
	} while (!(input > 0 && input <= 100)); // ���ϴ� ���� ���� ���ڸ� �Է¹��� ������ �Է¹���

	cout << "Success!" << endl; // ���ϴ� ���� ���� �ִٸ� �Է¹ޱ� ���߰� �����
	return 0;
}

*/
