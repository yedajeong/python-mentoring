#include <iostream>
#include <vector>
using namespace std;

//����01
int main() {
	vector<int> list{ 10, 20, 30, 40, 50 };
	int num;
	while (1) {
		cout << "��� �� ������ ��: ";
		cin >> num;
		try {
			for (int i = 0; i < num; i++)
				cout << list.at(i) << '\t';
			cout << endl;
		}
		catch (exception& e) {
			cout << endl << "Index is out of range. Please try again." << endl;
		}

		if (num == -1)
			break;
	}

	cout << "Program exit...";

	return 0;
}