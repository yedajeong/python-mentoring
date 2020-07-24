#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

//ÀÀ¿ë 04
int main() {
	string s1, s2;
	ofstream fout1("input1.txt"), fout2("input2.txt"), fout3("output.txt");
	ifstream fin1("input1.txt"), fin2("input2.txt");

	if (!fout1 | !fout2 | !fout3 | !fin1 | !fin2) {
		cout << "File Open Error" << endl;
		exit(100);
	}

	s1 = "On its 60th anniversary in 2009, Kyung";
	fout1 << s1 << endl;
	fout1 << "Hee University prepared for a second leap" << endl;
	fout1 << "forward while seeking a new paradigm of" << endl;
	fout1 << "future university development" << endl << endl;
	fout1.close();

	s2 = "In this paper, we explore the feasibility of a";
	fout2 << s2 << endl;
	fout2 << "medical trainig system for breast tumor palpation" << endl;
	fout2 << "based on haptic augmented reality (AR) technology" << endl;
	fout2.close();

	while (getline(fin1, s1)) {
		fout3 << s1 << endl;
	}

	while (getline(fin2, s2)) {
		fout3 << s2 << endl;
	}

	fout3.close();
	fin1.close();
	fin2.close();

	cout << "end";

	return 0;
}