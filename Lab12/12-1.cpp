#include <iostream>
#include <vector>
using namespace std;

//01
class Base {
protected: //Base type
	void print_base() { cout << "Base" << endl; }
};

//base type | ingeritance type     | derived type
//----------+----------------------+-------------
//private   | 상관 없이             | 접근 불가 (Base함수로 접근)
//protected | 상관 없이             | private
//public    | private/protected    | private
//public    | public               | public

class Derived : private Base {
public:
	void print_derived() {
		Base::print_base();
		cout << "Derived" << endl;
	}
};

int main() {
	Base base;
	Derived derived;

	derived.print_derived();

	return 0;
}
