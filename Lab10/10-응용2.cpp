#include <iostream>
#include <string>
using namespace std;

//응용 02
class CStudent {

private:
	int number;
	string name;
	string major;

public:
	CStudent()
		:number(2018000000), name("홍길동"), major("컴퓨터공학과") {}
	CStudent(int _number, string _name, string _major)
		:number(_number), name(_name), major(_major) {}

	void setNumber(int _number) { number = _number; }
	void setName(string _name) { name = _name; }
	void setMajor(string _major) { major = _major; }

	int getNumber() { return number; }
	string getName() { return name; }
	string getMajor() { return major; }

	void Display() {
		cout << "학번 : " << number << endl;
		cout << "이름 : " << name << endl;
		cout << "전공 : " << major << endl << endl;
	}
};

int main() {
	CStudent s[3]; //3명의 학생정보를 저장할 class 배열
	int inputNumber; //키보드로 학번을 입력 받을 변수
	string inputName, inputMajor; //키보드로 이름, 전공을 입력 받을 변수
	int length = 0; //현재 입력된 학생의 수

	while (1) {
		cout << length + 1 << " 번째 학생 입력" << endl << "학번 : ";
		cin >> inputNumber;
		s[length].setNumber(inputNumber);
		cout << "이름 : ";
		cin >> inputName;
		s[length].setName(inputName);
		cout << "전공 : ";
		cin >> inputMajor;
		s[length].setMajor(inputMajor);

		if (length != 0) { // lenght 1,2만 들어옴
			for (int i = 1; (length - i) >= 0; i++) {
				if (s[length].getNumber() == s[length - i].getNumber()) {
					cout << "※중복된 학번이 존재합니다" << endl << endl;
					length--;
					break;
				}

				else if ((length - i) != 0)
					continue;

				else {
					cout << "※입력 완료" << endl << endl;
					break;
				}
			}
		}
		else
			cout<<"※입력 완료" << endl << endl;

		if (length == 2 && (s[0].getNumber() != s[1].getNumber() != s[2].getNumber())) {
			cout << "----모든입력이 완료되었습니다----" << endl;
			for (int i = 1; i <= 3; i++) {
				cout << i << "학생정보" << endl;
				s[i - 1].Display();
			}
			break;
		}
		else
			length++;
	}

	return 0;
}