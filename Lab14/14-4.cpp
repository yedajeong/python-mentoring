#include <iostream>
#include <vector>
using namespace std;

//04
int main() {
	vector<int> v{ 1, 2, 3, 4 };

	int index;
	cin >> index;
	try {
	cout << v.at(index) << endl; 
	}
	catch (exception& e) {
		cout << e.what() << endl;
		cout << "�ε��� ����" << endl;
	}

	cout << "[Program is running]" << endl;
	return 0;
}