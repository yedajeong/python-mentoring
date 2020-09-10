#include <iostream>
#include <vector>
using namespace std;

//ÀÀ¿ë02
template <class Iter>
int max(Iter iter_begin1, Iter iter_end1, Iter iter_begin2, Iter iter_end2) {
	int maxNum = 0;
	for (Iter iter1 = iter_begin1; iter1 != iter_end1; iter1++) {
		for (Iter iter2 = iter_begin2; iter2 != iter_end2; iter2++) {
			int result = (*iter1) * (*iter2);
			if (result > maxNum)
				maxNum = result;
		}
	}
	return maxNum;
}

template <class Iter>
int min(Iter iter_begin1, Iter iter_end1, Iter iter_begin2, Iter iter_end2) {
	int minNum = 0;
	for (Iter iter1 = iter_begin1; iter1 != iter_begin1; iter1++) {
		for (Iter iter2 = iter_begin2; iter2 != iter_end2; iter2++) {
			int result = (*iter1) * (*iter2);
			if (result < minNum)
				minNum = result;
		}
	}
	return minNum;
}

template <class Iter>
void print(Iter iter_begin, Iter iter_end) {
	for (Iter iter = iter_begin; iter != iter_end; iter++)
		cout << "  " << *iter;
	cout << endl;
}

int main() {
	vector<int> v1(10);
	for (int i = 0; i < 10; i++)
		v1[i] = rand() % 11;

	vector<int> v2(10);
	for (int j = 0; j < 10; j++)
		v2[j] = rand() % 21;

	cout << "<vector 1>" << endl;
	print(begin(v1), end(v1));
	cout << "<vector 2>" << endl;
	print(begin(v2), end(v2));

	cout << endl << "ÃÖ´ñ°ª = " << max(begin(v1), end(v1), begin(v2), end(v2));
	cout << endl << "ÃÖ¼Ú°ª = " << min(begin(v1), end(v1), begin(v2), end(v2));

	return 0;
}