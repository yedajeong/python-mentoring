#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//02
int main() {
	int num = 1;
	int count = 1;
	cout.imbue(locale("")); // 세 자리(1,000)마다 쉼표 찍기 위함
	while (count <= 20) {
		num = pow(2, num);
		cout << count << '\t' << setw(10) << num << endl;
		count++;
	}

	return 0;
}