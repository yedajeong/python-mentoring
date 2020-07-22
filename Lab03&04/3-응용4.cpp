#include <iostream>
using namespace std;

void swap_call_by_value(int a, int b);
void swap_call_by_reference(int &a, int &b);
void get_data(int &x, int &y);

int main() {
	int x, y;
	get_data(x, y);

	cout << "swap_call_by_value함수 사용 전" << endl;
	cout << "x = " << x << '\t' << "y = " << y << endl;
	cout << "swap_call_by_value함수 사용 후" << endl;
	swap_call_by_value(x, y);
	cout << "x = " << x << '\t' << "y = " << y << endl << endl;

	cout << "swap_call_by_reference함수 사용 전" << endl;
	cout << "x = " << x << '\t' << "y = " << y << endl;
	cout << "swap_call_by_reference함수 사용 후" << endl;
	swap_call_by_reference(x, y);
	cout << "x = " << x << '\t' << "y = " << y << endl;
}

void swap_call_by_value(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}
void swap_call_by_reference(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
void get_data(int &x, int &y) {
	cout << "x 입력 : ";
	cin >> x;
	cout << "y 입력 : ";
	cin >> y;
}