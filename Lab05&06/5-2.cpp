#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//02
int main() {
	int num = 1;
	int count = 1;
	cout.imbue(locale("")); // �� �ڸ�(1,000)���� ��ǥ ��� ����
	while (count <= 20) {
		num = pow(2, num);
		cout << count << '\t' << setw(10) << num << endl;
		count++;
	}

	return 0;
}