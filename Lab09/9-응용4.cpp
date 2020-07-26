#include <iostream>
#include <iomanip>
using namespace std;

//응용 04
int** buildTable(int n) {
	int **table = new int*[n];
	for (int i = 0; i < n; i++) {
		table[i] = new int[n];
		for (int j = 0; j < n; j++)
			table[i][j] = 0;
	}
	return table;
}

void make_identity_matrix(int **table, int n) {
	for (int i = 0; i < n; i++) {
		table[i][i] = 1;
	}
}

void printTable(int **table, int n) {
	cout << "Output : " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << setw(4) << table[i][j];
		cout << endl;
	}
}

int main() {
	int n = 0;
	cout << "N을 입력하시오 : ";
	cin >> n;
	if (n < 1) {
		cout << "\n행렬을 생성할 수 없습니다.\n" << endl;
		exit(EXIT_FAILURE);
	}

	int **table = buildTable(n);
	make_identity_matrix(table, n);
	printTable(table, n);

	for (int i = 0; i < n; i++)
		delete[] table[i];
	delete[] table;

	return 0;
}