#include <iostream>
using namespace std;

//ÀÀ¿ë 3
int main() {
	int num, sum = 0;
	cout << "number : ";
	cin >> num;

	for (int i = 1; i <= num; i++)
	{
		if (i % 2 != 0 && i % 3 != 0) {
			sum += i;
		}
	}
	cout << "sum : " << sum;

	return 0;
}