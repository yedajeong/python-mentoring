#include <iostream>
using namespace std;

//응용 04
int main() {
	int dan;
	while (true) {
		cout << "단 수를 입력하세요: ";
		cin >> dan;
		if (dan >= 1 && dan <= 9) {
			for (int i = 1; i <= 9; i++)
			{
				cout << dan << '*' << i << '=' << (dan*i) << endl;
			}
		}
		else if (dan == -1) {
			cout << "종료합니다.";
			break;
		}
		else
			cout << "1부터 9까지의 정수를 입력해주세요." << endl;
	}
	
	return 0;
}