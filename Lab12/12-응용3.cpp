#include <iostream>
#include <string>
using namespace std;

//응용03
class Train {
public:
	Train() {}
	Train(int people) { mPeople = people; }
	~Train() {}
	virtual void station(int takeOff, int takeOn) {
		mPeople = mPeople - takeOff + takeOn;
	}
protected:
	int mPeople; //사람 수
};

class Ktx : public Train {
public:
	Ktx() : Train::Train(0) {} //처음에는 기차 안에 아무도 없음
	Ktx(int people) : Train::Train(people) {}
	~Ktx() {}
	//기차에 사람이 타고 내리는 함수
	void station(int takeOff, int takeOn) override {
		if (mPeople - takeOff < 0) { //기차안의 사람보다 더많은 사람이 내리는 경우
			cout << "정원미달입니다" << endl;
			exit(EXIT_FAILURE);
		}

		Train::station(takeOff, takeOn);

		if (mPeople > 300) { //station함수 호출 이후 기차안의 사람 300명 초과인 경우
			cout << "정원초과입니다" << endl;
			exit(EXIT_FAILURE);
		}
	}
	int getPeople() { //현재 타고있는 사람 수
		return mPeople;
	}
};

int main() {
	Ktx k;
	int takeOff, takeOn, maxPeople = 0;
	
	for (unsigned i = 1; i <= 5; i++) {
		cout << i << "번역: ";
		cin >> takeOff >> takeOn;

		k.station(takeOff, takeOn);

		if (k.getPeople() > maxPeople)
		maxPeople = k.getPeople();
	}

	cout << "가장 많은 사람이 탑승 했을 때의 사람 수 : " << maxPeople;

	return 0;
}