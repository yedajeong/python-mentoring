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
	} while (!(input > 0 && input <= 100)); // 원하는 범위 내의 숫자를 입력받을 때까지 입력받음

	cout << "Success!" << endl; // 원하는 범위 내에 있다면 입력받기 멈추고 출력함
	return 0;
}

*/
