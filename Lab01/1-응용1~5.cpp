#include <iostream>
using namespace std;

//응용01
int main(){
	cout << "My name is 홍길동" << endl;
	}

//응용02
int main(){
	int A, B;
	cout << "Please enter two integer values : "
	cin >> A >> B;
	cout << A << '+' << B << '=' << A+B << endl;
	cout << A << '-' << B << '=' << A-B << endl;
	cout << A << '*' << B << '=' << A*B << endl;
	cout << A << '/' << B << '=' << A/B << endl;
	cout << A << '%' << B << '=' << A%B << endl;
	}

//응용03
int main(){
	int i1 = 2, i2 = 5, i3 = -3;
	double d1 = 2.0, d2 = 5.0, d3 = -5.0;

	cout << i1 + (i2 * i3) << endl;
	cout << i1 * (i2 + i3) << endl;
	cout << i1 / (i2 + i3) << endl;
	cout << i1 / i2 + i3 << endl;
	cout << 3 + 4 + 5 / 3 << endl;
	cout << (3 + 4 + 5) / 3 << endl;
	cout << d1 + (d2 * d3) << endl;
	cout << d1 + d2 * d3 << endl;
	cout << d1 / d2 - d3 << endl;
	cout << d1 / (d2 - d3) << endl;
	cout << d1 + d2 + d3 / 3 << endl;
	cout << (d1 + d2 + d3) / 3 << endl;
	}

//응용04
int main(){
	int A, B, X;
	cout << "Please enter two integer values : " << endl;
	cin >> A >> B;
	X = A;
	A = B;
	B = X;
	cout << "value of A is : " << A << endl;
	cout << "value of B is : " << B << endl;
	}

//응용05
int main (){
	float Celsius, Fahrenheit;
	cout << "Please enter Fahrenheit value : << endl; 
	cin >> Fahrenheit;
	Celsius = 5.0f / 9.0f (Fahrenheit - 32);
	cout << "Celsius value is : " << Celsius << endl;
	}
*/
