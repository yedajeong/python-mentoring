#include <iostream>
using namespace std;

//���� 04
int main() {
	int dan;
	while (true) {
		cout << "�� ���� �Է��ϼ���: ";
		cin >> dan;
		if (dan >= 1 && dan <= 9) {
			for (int i = 1; i <= 9; i++)
			{
				cout << dan << '*' << i << '=' << (dan*i) << endl;
			}
		}
		else if (dan == -1) {
			cout << "�����մϴ�.";
			break;
		}
		else
			cout << "1���� 9������ ������ �Է����ּ���." << endl;
	}
	
	return 0;
}