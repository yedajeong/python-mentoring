#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class VectorList {
private:
	vector<double*> vItem; //Item (array)의 pointer 저장
	vector<int> vLength; //각 Item(array)의 길이 저장
public:
	~VectorList() {
		for (int i = 0; i < vLength.size(); i++)
			delete vItem[i];
	}

	void append(double* _pArray, int _length) {
		vItem.push_back(_pArray);
		vLength.push_back(_length);
	}

	int findVector(double* _pArray, int _length) {
		for (int i = 0; i < vLength.size(); i++) {
			if (vLength[i] == _length) {
				for (int j = 0; j < _length; j++) {
					if (vItem[i][j] != _pArray[j])
						return -1;
					else if (vItem[i][j] == _pArray[j] && j == _length - 1)
						return i;
				}
			}
			else if (vLength[i] != _length && i == vLength.size() - 1)
				return -1;
		}
	}

	void print_single_vector(int idx) {
		if (idx >= vLength.size())
			cout << "[Wrong index]" << endl;
		else {
			cout << idx << "-th vector: ";
			for (int i = 0; i < vLength[idx]; i++)
				cout << "\t" << vItem[idx][i];
			cout << endl;
		}
	}
	void print_all_vectors() {
		for (int i = 0; i < vLength.size(); i++)
			print_single_vector(i);
	}
};
int main() {
	VectorList vectorList;
	double* pTemp = new double[3]{ 1.1, 2.2, 3.3 };
	vectorList.append(pTemp, 3); //아이템 추가

	pTemp = new double[5]{ 10.1, 10.2, 10.3, 10.4, 10.5 };
	vectorList.append(pTemp, 5);

	pTemp = new double[2]{ 4.5, 5.5 };
	vectorList.append(pTemp, 2);

	vectorList.print_single_vector(-1);
	vectorList.print_single_vector(0);
	cout << endl;

	vectorList.print_all_vectors();
	cout << endl;

	double* pTemp1 = new double[2]{ 4.5, 5.5 };
	double* pTemp2 = new double[4]{ 1.1, 2.2, 5.5, 4.4 };
	cout << "Index of vector{4.5, 5.5} : " << vectorList.findVector(pTemp1, 2) << endl;
	cout << "Index of vector{1.1, 2.2, 5.5, 4.4} : " << vectorList.findVector(pTemp2, 4) << endl;

//	delete[] pTemp; main수정 안하는 건 조교님 코드 보기
	delete[] pTemp1;
	delete[] pTemp2;

	return 0;
}