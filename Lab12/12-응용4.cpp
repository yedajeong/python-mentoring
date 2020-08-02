#include <iostream>
#include <string>
using namespace std;

class Avengers {
public:
	Avengers() {
		name = "";
		attack_point = 0;
		defense_point = 0;
		health = 0;
	}
	~Avengers() {}
	//캐릭터 설정 함수
	virtual void set(string _name, int _attack, int _defense, int _health) {}
	//공격 함수
	virtual int attack() { return 0; }
	//방어 함수
	virtual void defense(int _attack_point) {}
	//캐릭터 정보 출력 함수
	virtual void print_info() {}
protected:
	string name;       //캐릭터 이름
	int attack_point;  //공격력
	int defense_point; //방어력
	int health;        //체력
};

class Character : public Avengers {
public:
	Character() : Avengers::Avengers() {}
	~Character() {}

	void set(string _name, int _attack, int _defense, int _health) override {
		name = _name;
		attack_point = _attack;
		defense_point = _defense;
		health = _health;
	}
	int attack() override { 
		return attack_point;
	}
	void defense(int _attack_point) override {
		health -= _attack_point - this->defense_point;
	}
	void print_info() override {
		cout << "Name: " << name << endl
			<< "Attack_Point: " << attack_point << endl
			<< "Defense_Point: " << defense_point << endl
			<< "Health: " << health << endl;
	}
	int get_health() { return health; }
};

int main() {
	Character my_char;
	Character enemy_char;

	string inputChar;
	int randNum;
	string charName[3] = { "IronMan", "CaptainAmerica", "Thor" };

	//my_char 캐릭터 설정
	cout << "Choose your character(IronMan, CaptainAmerica, Thor): ";
	cin >> inputChar;
	if (inputChar == "IronMan")
		my_char.set(inputChar, 70, 40, 100);
	else if (inputChar == "CaptainAmerica")
		my_char.set(inputChar, 60, 50, 100);
	else if (inputChar == "Thor")
		my_char.set(inputChar, 80, 30, 100);

	//enemy_char 캐릭터 설정
	randNum = rand() % 3; //0~2의 난수 생성->charName배열의 랜덤 index로 사용
	if (randNum == 0)
		enemy_char.set(charName[0], 70, 40, 100);
	else if (randNum == 1)
		enemy_char.set(charName[1], 60, 50, 100);
	else if (randNum == 2)
		enemy_char.set(charName[2], 80, 30, 100);

	cout << "--My Character--" << endl;
	my_char.print_info();
	cout << "--Enemy Character--" << endl;
	enemy_char.print_info();
	

	cout << endl << "--Batle--" << endl;
	cout << "My Life: " << my_char.get_health() << "\t"
		<< "Enemy Life: " << enemy_char.get_health() << endl;

	while (1) {
		//자신의 캐릭터 선공
		enemy_char.defense(my_char.attack());
		if (enemy_char.get_health() <= 0) {
			cout << "My Life: " << my_char.get_health() << "\t"
				<< "Enemy Life: 0" << endl
				<< "You Win!" << endl;
			break;
		}
		else {
			cout << "My Life: " << my_char.get_health() << "\t"
				<< "Enemy Life: " << enemy_char.get_health() << endl;
		}
		//상대방 캐릭터 후공
		my_char.defense(enemy_char.attack());
		if (my_char.get_health() <= 0) {
			cout << "My Life: 0" << "\t"
				<< "Enemy Life: " << enemy_char.get_health() << endl
				<< "You Lose!" << endl;
		}
		else {
			cout << "My Life: " << my_char.get_health() << "\t"
				<< "Enemy Life: " << enemy_char.get_health() << endl;
		}
	}

	return 0;
}