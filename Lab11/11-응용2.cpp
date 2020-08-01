#include <iostream>
#include <string>
using namespace std;

//����02
class Account {
private:
	string name;
	string id;
	int balance;
public:
	Account(string _name = "xxx", string _id = "xxxx", int _balance = 0)
		: name(_name), id(_id), balance(_balance) {}

	string getName() const { return name; }
	string getId() const { return id; }
	int getBal() const { return balance; }

	Account operator-(Account& ac) {
		this->balance -= ac.balance;
		return *(this);
	}

	Account operator+(Account& ac) {
		this->balance += ac.balance;
		return *(this);
	}

	Account operator=(Account ac) {
		this->name = ac.name;
		this->id = ac.id;
		this->balance = ac.balance;
		return *(this);
	}

	friend ostream& operator<<(ostream& cout, const Account& ac);

};

ostream& operator<<(ostream& cout, const Account& ac) {
	cout << "�й� : " << ac.getId() << ", �̸� : " << ac.getName() << ", �ܾ� : " << ac.getBal() << endl;
	return cout;
}

int main() {
	Account acnt[3] = {
		Account("����ȣ", "2014", 10000),
		Account("������", "2019", 0),
		Account("������", "2013", 5000)
	};

	string inputSendId, inputRecId;

	while (1) {
		int sendIdx = -1, recIdx = -1;

		cout << "���� ���� �л��� �й��� �Է��ϼ���: ";
		cin >> inputSendId;
		
		if (inputSendId == "����") {
			cout << "�����մϴ�." << endl;
			for (unsigned i = 0; i < (sizeof(acnt)/sizeof(acnt[0])); i++)
				cout << acnt[i];
			break;
		}

		cout << "���� ���� �л��� �й��� �Է��ϼ���: ";
		cin >> inputRecId;

		if (inputSendId == inputRecId) {
			cout << "���� ���� �л��� ���� �л��� �й��� �����մϴ�. �ٽ� �Է����ּ���" << endl;
			continue;
		}

		for (unsigned i = 0; i < (sizeof(acnt) / sizeof(acnt[0])); i++) {
			if (inputSendId == acnt[i].getId()) {
				sendIdx = i;
			}
			else if (inputRecId == acnt[i].getId()) {
				recIdx = i;
			}
		}

		//�� for������ sendIdx�� recIdx�� ���� �ε����� ������� �ʾҴٸ� �״�� -1
		if (sendIdx == -1 || recIdx == -1) {
			cout << "������ �л� Ȥ�� ���� �л��� �й��� �������� �ʽ��ϴ�. �ٽ� �Է����ּ���." << endl;
			continue;
		}
		else if (acnt[sendIdx].getBal() == 0) {
			cout << "������ �л��� �ܾ��� �����մϴ�. �ٽ� �Է����ּ���." << endl;
			continue;
		}

		acnt[recIdx] = acnt[recIdx] + acnt[sendIdx];
		acnt[sendIdx] = acnt[sendIdx] - acnt[sendIdx];

		cout << "���� �л��� �ܾ� => " << acnt[sendIdx];
		cout << "���� �л��� �ܾ� => " << acnt[recIdx];

	}
}