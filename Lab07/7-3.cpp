#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//03
int main() {
	double d1 = 1.23456789;
	
	cout << d1 << endl;
	cout.width(10);
	cout.precision(3);
	cout << d1 << endl;

	char ch1;
	char ch2;

	// ch1, ch2 : enter " z". (space + z)
	cin >> ch1;
	cout << "(" << ch1 << ")" << endl;

	cin.ignore(); // enter가 다음 cin으로 들어가지 않도록 해줌

	cin.unsetf(ios::skipws);
	cin >> ch2;
	cout << "(" << ch2 << ")" << endl;
	

	return 0;
}