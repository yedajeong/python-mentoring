#include <iostream>
#include <string>
#include <fstream> 
using namespace std;

//ÀÀ¿ë 05
int main() {
	ifstream fin("before.txt");
	ofstream fout("after.txt");
	string s, line;
	int length;

	if (!fin | !fout) {
		cout << "File Open Error";
		exit(100);
	}

	cout << "length = ";
	cin >> length;

	while (getline(fin, s)) {
		line += s;
	}

	int i = 0;
	while (line.find('.', i) != string::npos) {
		s = line.substr(i, length);
		fout << s << endl;
		i += length;
	}

	fin.close();
	fout.close();

	cout << "end";

	return 0;
}
