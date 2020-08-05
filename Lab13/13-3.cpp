#include <iostream>
#include <vector> //���� search, ���p pop/push
#include <list> //���� search, ���� pop/push
using namespace std;

//03
int main() {
	list<int> myList{ 1, 2, 3, 4 };
	char command;
	int inputVal;
	bool finished = false;
	while (!finished) {
		//command�� �Է¹���
		cout << "I)nput, P)rint, L)ength, E)mpty, Q)uit>>";
		cin >> command;

		//command������ ��� ����
		switch (command) {
		case 'I':
		case 'i':
			cin >> inputVal;
			myList.push_back(inputVal);
			break;
		case 'P':
		case 'p':
			for (int elem : myList)
				cout << elem << '\t';
			cout << endl;
			break;
		case'L':
		case'l':
			cout << "Number of items: " << myList.size() << endl;
			break;
		case'E':
		case'e':
			myList.clear();
			break;
		case'Q':
		case'q':
			finished = true;
			cout << "Exit the program" << endl;
			break;
		default:
			cout << "Wrong command" << endl;
			break;
		}
	}
	return 0;
}