#include <iostream>
#include <string>
using namespace std;

//����03
class Train {
public:
	Train() {}
	Train(int people) { mPeople = people; }
	~Train() {}
	virtual void station(int takeOff, int takeOn) {
		mPeople = mPeople - takeOff + takeOn;
	}
protected:
	int mPeople; //��� ��
};

class Ktx : public Train {
public:
	Ktx() : Train::Train(0) {} //ó������ ���� �ȿ� �ƹ��� ����
	Ktx(int people) : Train::Train(people) {}
	~Ktx() {}
	//������ ����� Ÿ�� ������ �Լ�
	void station(int takeOff, int takeOn) override {
		if (mPeople - takeOff < 0) { //�������� ������� ������ ����� ������ ���
			cout << "�����̴��Դϴ�" << endl;
			exit(EXIT_FAILURE);
		}

		Train::station(takeOff, takeOn);

		if (mPeople > 300) { //station�Լ� ȣ�� ���� �������� ��� 300�� �ʰ��� ���
			cout << "�����ʰ��Դϴ�" << endl;
			exit(EXIT_FAILURE);
		}
	}
	int getPeople() { //���� Ÿ���ִ� ��� ��
		return mPeople;
	}
};

int main() {
	Ktx k;
	int takeOff, takeOn, maxPeople = 0;
	
	for (unsigned i = 1; i <= 5; i++) {
		cout << i << "����: ";
		cin >> takeOff >> takeOn;

		k.station(takeOff, takeOn);

		if (k.getPeople() > maxPeople)
		maxPeople = k.getPeople();
	}

	cout << "���� ���� ����� ž�� ���� ���� ��� �� : " << maxPeople;

	return 0;
}