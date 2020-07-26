#include <iostream>
#include <vector>
#include <iomanip>
#include <ctime>
using namespace std;
using Matrix = vector<vector<int>>;

//응용 01
void reset(Matrix &mat) {
	for (unsigned row = 0; row < mat.size(); row++) {
		for (unsigned col = 0; col < mat[0].size(); col++) {
			int elem = rand() % 19 - 9;
			mat[row][col] = elem;
		}
	}
}

void print(const Matrix &mat) {
	for (const auto &row : mat) {
		for (auto elem : row)
			cout << setw(4) << elem;
		cout << endl;
	}
	cout << endl;
}

void vecMul(const Matrix &mat1, const Matrix &mat2) {

	if (mat1[0].size() != mat2.size()) {
		cout << "두 행렬을 곱할 수 없습니다.";
		exit(EXIT_FAILURE);
	}
	else {
		cout << endl << "AB 곱행렬 : " << endl;
		for (unsigned i = 0; i < mat1.size(); i++) {
			for (unsigned j = 0; j < mat2[0].size(); j++) {
				int result = 0;
				for (unsigned k = 0; k < mat2.size(); k++) {
					result += mat1[i][k] * mat2[k][j];
				}
				cout << setw(4) << result;
			}
			cout << endl;
		}
	}
}

int main() {
	int rowA, colA, rowB, colB;
	cout << "A의 행, 열의 크기를 입력해주세요 : ";
	cin >> rowA >> colA;
	cout << "B의 행, 열의 크기를 입력해주세요 : ";
	cin >> rowB >> colB;

	if (rowA == 0 || colA == 0 || rowB == 0 || colB == 0) {
		cout << endl << "행렬을 생성할 수 없습니다." <<endl;
		exit(EXIT_FAILURE);
	}

	Matrix matA(rowA, vector<int>(colA));
	Matrix matB(rowB, vector<int>(colB));

	reset(matA);
	reset(matB);

	cout << "A 행렬 : " << endl;
	print(matA);
	cout << "B 행렬 : " << endl;
	print(matB);

	vecMul(matA, matB);

	return 0;
}