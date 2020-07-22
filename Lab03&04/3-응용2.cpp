#include <iostream>
using namespace std;

//06
void print_DOB(int year = 1900, int month = 1, int day = 1);

int main() {
	int userY, userM, userD;
	print_DOB();
	cout << "year 입력 : ";
	cin >> userY;
	cout << "month 입력 : ";
	cin >> userM;
	cout << "day 입력 : ";
	cin >> userD;
	print_DOB(userY, userM, userD);

	return 0;
}

void print_DOB(int year, int month, int day) {
	cout << "생년월일은 " << year << "년 " << month << "월 " << day << "일 입니다." << endl;
}