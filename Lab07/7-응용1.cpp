#include <iostream>
#include <string>

using namespace std;

//응용 01
int main() {
	string city, area, street, building, address;
	cout << "시 : ";
	cin >> city;
	cout << "구 : ";
	cin >> area;
	cout << "로 : ";
	cin >> street;
	cout << "건물명 : ";
	cin >> building;

	address = city + area + street + building;

	cout << endl << "집 주소 : " << address;

	return 0;
}