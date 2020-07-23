#include <iostream>
#include <iomanip>
using namespace std;

//05
int main() {
	int n, m, row = 1, col = 1;
	cout << "Enter n for n x m matrix: ";
	cin >> n;
	cout << "Enter m for n x m matrix: ";
	cin >> m;

	while (row <= n) {
		while (col <= m) {
			cout << setw(4) << col * row;
			col++;
		}
		cout << endl;
		col = 1;
		row++;
	}

	return 0;
}