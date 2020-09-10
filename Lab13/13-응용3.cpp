#include <iostream>
#include <string>
using namespace std;

//응용03
int main() {
	string input;
	while (1) {
		cout << "문자열 하나를 입력해주세요 : ";
		cin >> input;

		if (input == "Q" || input == "q") {
			cout << "프로그램을 종료합니다" << endl;
			break;
		}

		[input]() {
			string reverse;
			for (unsigned i = input.size() - 1; i != -1; i--)
				reverse += input[i];
			cout << "입력하신 문자열의 역순 : " << reverse << endl;

			if (input == reverse)
				cout << "이 문자는 회문입니다." << endl << endl;
			else
				cout << "이 문자는 회문이 아닙니다." << endl << endl;
		} ();
	}
	
	return 0;
}