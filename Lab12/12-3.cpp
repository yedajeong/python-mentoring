#include "LabFancyText.h"
#include "LabFixedText.h"
using namespace std;

//03
int main() {
	Text t1("Plain");
	t1.append("A");
	cout << t1.get() << endl;

	FancyText t2("Fancy", "<<", ">>", "***");
	t2.append("A");
	cout << t2.get() << endl;

	FixedText t3;
	t3.append("A");
	cout << t3.get() << endl;
	t1 = t2; // Base <- Derived 가능
//	t2 = t1; // Derived <- Based 불가능

	return 0;
}