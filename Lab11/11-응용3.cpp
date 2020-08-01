#include <iostream>
#include <string>
using namespace std;

//����3
class Account {
private:
	string name;
	string id;
	int balance;
	static int total;
public:
	Account(string _name = "xxx", string _id = "xxxx", int _balance = 0)
		: name(_name), id(_id), balance(_balance) {	}

	~Account() {
		total += balance;
	}

	string getName() const { return name; }
	string getId() const { return id; }
	int getBal() const { return balance; }
	int getTotal() const { return total; }
};

int Account::total = 0;

int main() {
	int numStu;
	string inputId, inputName;
	int inputBal;
	cout << "�� �л� �� �Է�: ";
	cin >> numStu;
	Account* acnt = new Account[numStu];

	for (unsigned i = 0; i < numStu; i++) {
		cout << i + 1 << "��° �л� ���� �Է� : " << endl << "�й� : ";
		cin >> inputId;
		cout << endl << "�̸� : ";
		cin >> inputName;
		cout << endl << "�ܾ� : ";
		cin >> inputBal;
		cout << "=================================" << endl << endl;
		acnt[i] = Account(inputName, inputId, inputBal);

		if (i != 0) {
			for (unsigned j = 0; j < i; j++) { 
				if (acnt[i].getId() == acnt[j].getId() && i != j) //i!=j�ε� .getId()�� ���� ��
				{
					cout << "�ߺ��� �й��� �Է��Ͽ����ϴ�." << endl;
					exit(EXIT_FAILURE);
				}
			}
		}
	}

	cout << "ȸ���� �ݾ� : " << acnt[0].getTotal();
	delete[] acnt;
	
	return 0;
}