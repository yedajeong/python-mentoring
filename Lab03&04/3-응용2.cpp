#include <iostream>
using namespace std;

//06
void print_DOB(int year = 1900, int month = 1, int day = 1);

int main() {
	int userY, userM, userD;
	print_DOB();
	cout << "year �Է� : ";
	cin >> userY;
	cout << "month �Է� : ";
	cin >> userM;
	cout << "day �Է� : ";
	cin >> userD;
	print_DOB(userY, userM, userD);

	return 0;
}

void print_DOB(int year, int month, int day) {
	cout << "��������� " << year << "�� " << month << "�� " << day << "�� �Դϴ�." << endl;
}