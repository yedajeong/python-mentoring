#include <iostream>
#include <iomanip>
using namespace std;

//03
int main() {
	int row = 1, col = 1;
	while (row <= 10) {
		while (col <= 10) {
			int num;
			if (row == col)
				num = 1;
			else
				num = 0;
			cout << setw(4) << num;
			col++;
		}
		cout << endl;
		row++;
		col = 1;
	}
	return 0;
}