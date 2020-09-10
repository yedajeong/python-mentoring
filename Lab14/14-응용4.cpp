#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//응용04
class FileNotFoundException : public  exception {
	string message;
public:
	FileNotFoundException(string _m) :
		message("File \"" + _m + "\" not found ") {}
	virtual const char* what() const throw() {
		return message.c_str();
	}
};

ifstream file_open(string filename) {
	ifstream fin(filename);

	if (!fin) {
		throw FileNotFoundException(filename);
	}

	return fin;
}

int main() {
	ofstream ofs;
	ofs.open("temp.txt");
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			ofs << rand() % 101 << "\t";
		}
		ofs << endl;
	}
	ofs.close();

	string input;
	int row, col, n;
	ifstream ifs;

	try {
		cout << "파일 이름: ";
		cin >> input;
		ifs = file_open(input);
	}
	catch (exception& e) {
		cout << endl << e.what() << endl;
		exit(EXIT_FAILURE);
	}

	cout << "출력할 행 크기: ";
	cin >> row;
	cout << "출력할 열 크기: ";
	cin >> col;

	vector<vector<int>> v(10, vector<int>(10));
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			ifs >> n;
			v[i][j] = n;
		}
	}

	try {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++)
				cout << v.at(i).at(j) << "\t";
			cout << endl;
		}
	}
	catch (exception& e) {
		cout << endl << e.what() << endl;
	}


	ifs.close();

	return 0;
}