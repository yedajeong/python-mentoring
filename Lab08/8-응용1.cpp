#include <iostream>
using namespace std;

//ÀÀ¿ë 01
void mySqure(int *p) {
	cout << "Á¦°ö°ª> " << (*p * *p);
}
int main() {
	int input;
	cout << "input> ";
	cin >> input;
	int *inputP = &input;

	mySqure(inputP);

	return 0;
}