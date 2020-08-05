#include <iostream>
#include <vector>
using namespace std;

//04
int main() {
	int ary[] = { 1, 2, 3, 4 };
	int *pBegin, *pEnd;
	pBegin = ary;
	pEnd = ary + 4;
	for (int* pIter = pBegin; pIter < pEnd; pIter++)
		cout << *pIter << "\t";
	cout << endl;
	//auto, begin(), end()
	vector<int> v{ 10, 20, 30, 40 };
	auto iter_begin = begin(v);
	auto iter_end = end(v);
	for (auto iter = iter_begin; iter < iter_end; iter++)
		cout << *iter << "\t";
	cout << endl;

	return 0;
}