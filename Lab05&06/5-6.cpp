#include <iostream>
using namespace std;

//06
int main() {
	char key;
	cout << "Enter a key (p or q): ";
	cin >> key;

	switch (key) {
	case 'P':
	case 'p':
		cout << "Pause" << endl;
		break;
	case 'Q':
	case 'q':
		cout << "Quit" << endl;
		break;
	default:
		cout << "Invalid key" << endl;
		break;
	}

	return 0;
}