#include <iostream>
#include <string>
using namespace std;

//���� 02
class CStudent {

private:
	int number;
	string name;
	string major;

public:
	CStudent()
		:number(2018000000), name("ȫ�浿"), major("��ǻ�Ͱ��а�") {}
	CStudent(int _number, string _name, string _major)
		:number(_number), name(_name), major(_major) {}

	void setNumber(int _number) { number = _number; }
	void setName(string _name) { name = _name; }
	void setMajor(string _major) { major = _major; }

	int getNumber() { return number; }
	string getName() { return name; }
	string getMajor() { return major; }

	void Display() {
		cout << "�й� : " << number << endl;
		cout << "�̸� : " << name << endl;
		cout << "���� : " << major << endl << endl;
	}
};

int main() {
	CStudent s[3]; //3���� �л������� ������ class �迭
	int inputNumber; //Ű����� �й��� �Է� ���� ����
	string inputName, inputMajor; //Ű����� �̸�, ������ �Է� ���� ����
	int length = 0; //���� �Էµ� �л��� ��

	while (1) {
		cout << length + 1 << " ��° �л� �Է�" << endl << "�й� : ";
		cin >> inputNumber;
		s[length].setNumber(inputNumber);
		cout << "�̸� : ";
		cin >> inputName;
		s[length].setName(inputName);
		cout << "���� : ";
		cin >> inputMajor;
		s[length].setMajor(inputMajor);

		if (length != 0) { // lenght 1,2�� ����
			for (int i = 1; (length - i) >= 0; i++) {
				if (s[length].getNumber() == s[length - i].getNumber()) {
					cout << "���ߺ��� �й��� �����մϴ�" << endl << endl;
					length--;
					break;
				}

				else if ((length - i) != 0)
					continue;

				else {
					cout << "���Է� �Ϸ�" << endl << endl;
					break;
				}
			}
		}
		else
			cout<<"���Է� �Ϸ�" << endl << endl;

		if (length == 2 && (s[0].getNumber() != s[1].getNumber() != s[2].getNumber())) {
			cout << "----����Է��� �Ϸ�Ǿ����ϴ�----" << endl;
			for (int i = 1; i <= 3; i++) {
				cout << i << "�л�����" << endl;
				s[i - 1].Display();
			}
			break;
		}
		else
			length++;
	}

	return 0;
}