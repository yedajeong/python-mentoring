#include <iostream>
#include <string>
using namespace std;

//응용3
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
	cout << "총 학생 수 입력: ";
	cin >> numStu;
	Account* acnt = new Account[numStu];

	for (unsigned i = 0; i < numStu; i++) {
		cout << i + 1 << "번째 학생 계좌 입력 : " << endl << "학번 : ";
		cin >> inputId;
		cout << endl << "이름 : ";
		cin >> inputName;
		cout << endl << "잔액 : ";
		cin >> inputBal;
		cout << "=================================" << endl << endl;
		acnt[i] = Account(inputName, inputId, inputBal);

		if (i != 0) {
			for (unsigned j = 0; j < i; j++) { 
				if (acnt[i].getId() == acnt[j].getId() && i != j) //i!=j인데 .getId()가 같을 때
				{
					cout << "중복된 학번을 입력하였습니다." << endl;
					exit(EXIT_FAILURE);
				}
			}
		}
	}

	cout << "회수된 금액 : " << acnt[0].getTotal();
	delete[] acnt;
	
	return 0;
}