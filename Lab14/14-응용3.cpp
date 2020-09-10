#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

//응용03
class FileNotFoundException : public exception {
	string message;
public:
	FileNotFoundException(const string& fname) :
		message("File \"" + fname + "\" not found") {}

	virtual const char* what() const throw () {
		return message.c_str();
	}
};
class CStudent
{
private:
	string m_Name;
	int m_Number;
	string m_Major;
public:
	CStudent() {}
	~CStudent() {}
	void setAll(string _name, int _num, string _maj) {
		m_Name = _name;
		m_Number = _num;
		m_Major = _maj;
	}
	void Display() {
		cout << "이름: " << m_Name << endl;
		cout << "학번: " << m_Number << endl;
		cout << "전공: " << m_Major << endl << endl;
	}
};
vector<CStudent> read_file(string& filename) {
	string name, major;
	int number, data_count;
	vector<CStudent> result;
	CStudent student;
	ifstream fin(filename);

	if (fin) { //if-else로 하니까 됨, 마지막 예제처럼 try-catch(throw)해서 가까운 함수에게 전달전달하면 안됨ㅜ 왜지?
		fin >> data_count;

		for (int i = 0; i < data_count; i++) {
			fin >> name >> number >> major;
			student.setAll(name, number, major);
			result.push_back(student);
		}
		return result;
	}
	else {
		throw FileNotFoundException(filename);
	}
}

int main() {
	string str;

	cout << "파일 이름 : ";
	cin >> str;

	try {
		vector<CStudent> numbers = read_file(str);
		for (CStudent value : numbers)
			value.Display();
	}
	catch (std::exception& e) { //std 네임스페이스 왜 쓰는거지?
		cout << e.what() << "\n";
	}

	return 0;
}