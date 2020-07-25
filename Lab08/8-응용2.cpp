#include <iostream>
#include <string>
using namespace std;

//응용 02
void transStr(string *p) {
	string userStr;
	cout << "input> ";
	cin >> userStr;
	*p = userStr;
}
int main() {
	string str = "This is default value";
	string *strP = &str;
	cout << "기본값 출력> " << str << endl;
	transStr(strP);
	cout << "변환된 값 출력> " << str << endl;

	return 0;
}