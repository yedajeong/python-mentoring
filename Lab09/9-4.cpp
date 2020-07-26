#include <iostream>
#include <iomanip>
using namespace std;

//03
//정적 배열(static array) : 프로그램 실행중 크기가 고정되어 변경 불가
//동적배열(dynamic array) : 프로그램 실행중(run-time) 할당/해제가 가능
int main() {
	const int size = 3;
	int list[size] = { 10, 20, 30 };

	int length = 3;
	cin >> length; // 키보드로부터 배열의 크기를 입력받음
	//new:int형 원소를 length만큼 블락(메모리 공간)에 할당,그 때 블락의 시작주솟값(index로 [0])을 저장하는 포인터가 list2가 됨, 동적배열을 만듦
	int *list2 = new int[length]; //동적 배열 선언
//	double *list2 = new double[length];

	int *begin = list2;
	int *end = list2 + length;

	for (int*curr = begin; curr != end; curr++)
		cin >> *curr;

	for (int*curr = begin; curr != end; curr++)
		cout << *curr << '\t';
	cout << endl;

	delete[] list2; //동적 배열 할당 해제

	return 0;
}