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
	//ĳ���� ���� �Լ�
	virtual void set(string _name, int _attack, int _defense, int _health) {}
	//���� �Լ�
	virtual int attack() { return 0; }
	//��� �Լ�
	virtual void defense(int _attack_point) {}
	//ĳ���� ���� ��� �Լ�
	virtual void print_info() {}
protected:
	string name;       //ĳ���� �̸�
	int attack_point;  //���ݷ�
	int defense_point; //����
	int health;        //ü��
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

	//my_char ĳ���� ����
	cout << "Choose your character(IronMan, CaptainAmerica, Thor): ";
	cin >> inputChar;
	if (inputChar == "IronMan")
		my_char.set(inputChar, 70, 40, 100);
	else if (inputChar == "CaptainAmerica")
		my_char.set(inputChar, 60, 50, 100);
	else if (inputChar == "Thor")
		my_char.set(inputChar, 80, 30, 100);

	//enemy_char ĳ���� ����
	randNum = rand() % 3; //0~2�� ���� ����->charName�迭�� ���� index�� ���
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
		//�ڽ��� ĳ���� ����
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
		//���� ĳ���� �İ�
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