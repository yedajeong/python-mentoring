#include <iostream>
using namespace std;

class Complex {
	double re, im;
public:
	Complex(double r, double i) { re = r; im = i; }
	Complex() { re = 0; im = 0; }

	Complex operator+(const Complex& com) {
		Complex result(this->re + com.re, this->im + com.im);
		return result;
	}

	Complex operator+(double num) {
		Complex result(this->re + num, this->im);
		return result;
	}

	Complex operator-(const Complex& com) {
		Complex result(this->re - com.re, this->im - com.im);
		return result;
	}

	Complex operator-(double num) {
		Complex result(this->re - num, this->im);
		return result;
	}

	void print() {
		cout << re << " + i" << im << endl;
	}
};

int main() {
	Complex a(.3, 8.4), b(4.5, 5.2), c(2.0, 7.7);
	Complex sum, dif;
	sum = a + b + 3.0;
	cout << "a + b + 3.0 = ";
	sum.print();

	dif = a - b - 2.0;
	cout << "a - b - 2.0 = ";
	dif.print();

	sum = a + b + 5 - c - 8;
	cout << "a + b + 5 - c - 8 = ";
	sum.print();

	return 0;
}