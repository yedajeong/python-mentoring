#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

//05
class FileNotFoundException : public  exception {
	string message;
public:
	FileNotFoundException(string _m) :
		message("File not found: " + _m) {}
	virtual const char* what() const throw() {
		return message.c_str();
	}
};

vector<int> load_vector(string filename) {
	ifstream fin(filename);

	if (!fin) {
		throw FileNotFoundException(filename);
	}

	vector<int> result;
	int num, value;
	fin >> num;
	for (int i = 0; i < num; i++) {
		fin >> value;
		result.push_back(value);
	}
	return result;
}

int main() {
	try {
		vector<int> v = load_vector("values.txt");
		for (int elem : v)
			cout << elem << '\t';
		cout << endl;
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}

	return 0;
}