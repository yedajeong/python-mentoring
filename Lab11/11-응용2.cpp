#include <iostream>
#include <string>
using namespace std;

//응용02
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
	cout << "학번 : " << ac.getId() << ", 이름 : " << ac.getName() << ", 잔액 : " << ac.getBal() << endl;
	return cout;
}

int main() {
	Account acnt[3] = {
		Account("장윤호", "2014", 10000),
		Account("김유민", "2019", 0),
		Account("박진배", "2013", 5000)
	};

	string inputSendId, inputRecId;

	while (1) {
		int sendIdx = -1, recIdx = -1;

		cout << "돈을 보낼 학생의 학번을 입력하세요: ";
		cin >> inputSendId;
		
		if (inputSendId == "종료") {
			cout << "종료합니다." << endl;
			for (unsigned i = 0; i < (sizeof(acnt)/sizeof(acnt[0])); i++)
				cout << acnt[i];
			break;
		}

		cout << "돈을 받을 학생의 학번을 입력하세요: ";
		cin >> inputRecId;

		if (inputSendId == inputRecId) {
			cout << "돈을 보낼 학생과 받을 학생의 학번이 동일합니다. 다시 입력해주세요" << endl;
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

		//위 for문에서 sendIdx나 recIdx에 새로 인덱스가 저장되지 않았다면 그대로 -1
		if (sendIdx == -1 || recIdx == -1) {
			cout << "보내는 학생 혹은 받을 학생의 학번이 존재하지 않습니다. 다시 입력해주세요." << endl;
			continue;
		}
		else if (acnt[sendIdx].getBal() == 0) {
			cout << "보내는 학생의 잔액이 부족합니다. 다시 입력해주세요." << endl;
			continue;
		}

		acnt[recIdx] = acnt[recIdx] + acnt[sendIdx];
		acnt[sendIdx] = acnt[sendIdx] - acnt[sendIdx];

		cout << "보낸 학생의 잔액 => " << acnt[sendIdx];
		cout << "받은 학생의 잔액 => " << acnt[recIdx];

	}
}