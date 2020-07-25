#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

//응용 03
void reverse( const vector<int> &v ){
	for (unsigned i = 0; i < v.size(); i++)
	{
		unsigned index = v.size() - 1 - i;
		cout << setw(4) << v[index];
	}
}

int main() {
	vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	cout << "기본 Vector 값: " << endl;
	for (int elem : vec)
		cout << setw(4) << elem;

	cout << endl << "함수 실행 후 Vector 값:" << endl;
	reverse(vec);

	return 0;
}