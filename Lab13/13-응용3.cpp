#include <iostream>
#include <string>
using namespace std;

//����03
int main() {
	string input;
	while (1) {
		cout << "���ڿ� �ϳ��� �Է����ּ��� : ";
		cin >> input;

		if (input == "Q" || input == "q") {
			cout << "���α׷��� �����մϴ�" << endl;
			break;
		}

		[input]() {
			string reverse;
			for (unsigned i = input.size() - 1; i != -1; i--)
				reverse += input[i];
			cout << "�Է��Ͻ� ���ڿ��� ���� : " << reverse << endl;

			if (input == reverse)
				cout << "�� ���ڴ� ȸ���Դϴ�." << endl << endl;
			else
				cout << "�� ���ڴ� ȸ���� �ƴմϴ�." << endl << endl;
		} ();
	}
	
	return 0;
}