#include <iostream>
using namespace std;

//���� 01
int main() {
	int num;
	int count = 1;

	do {
		cout << count << "��° ���� : ";
		cin >> num;
		if (num % 2 == 0)
			cout << num << "��(��) ¦���Դϴ�." << endl;
		else
			cout << num << "��(��) Ȧ���Դϴ�." << endl;
		count++;
	} while (count <= 5);

	return 0;
}