#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

//02
class Account {
//private: //�������
	string name;
	string id;
	double balance;
public: //����Լ�(method)
	//3���� ������ ����
	Account() {
		name = " ";
		id = " ";
		balance = 0.0;
	}
	Account(string _name, string _id) {
		name = _name;
		id = _id;
		balance = 0;
	}
	Account(string _name, string _id, double _bal) 
		:name(_name), id(_id), balance(_bal) {
		if (balance < 0)
			balance = 0;
	}
	
	void deposit(double _amt) { balance += _amt; }
	bool withdraw(double _amt) {
		if (balance - _amt < 0)
			return false;
		balance -= _amt;
		return true;
	}
	void print() {
		cout << name << ", " << id << ", " << balance << endl <<endl;
	}
};

int main() {
	Account ac1("�輺ȣ", "1002", 5000); 
	Account ac2; 
	ac2.print();
	ac1.print();

	int depo;
	cout << "������ �ݾ��� �Է��ϼ��� : ";
	cin >> depo;
	ac1.deposit(depo);
	ac1.print();

	int wdrw;
	cout << "����� �ݾ��� �Է��ϼ��� : ";
	cin >> wdrw;
	if (!ac1.withdraw(wdrw))
		cout << "�ܾ��� �����մϴ�." << endl;
	ac1.print();

	return 0;
}