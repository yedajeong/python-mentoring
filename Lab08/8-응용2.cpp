#include <iostream>
#include <string>
using namespace std;

//���� 02
void transStr(string *p) {
	string userStr;
	cout << "input> ";
	cin >> userStr;
	*p = userStr;
}
int main() {
	string str = "This is default value";
	string *strP = &str;
	cout << "�⺻�� ���> " << str << endl;
	transStr(strP);
	cout << "��ȯ�� �� ���> " << str << endl;

	return 0;
}