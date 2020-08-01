#include <iostream>
#include <string>
using namespace std;

//02

//�Լ� �����ε� : int    sum(int x, int y)
//				 double sum(double x, double y)
//				 float  sum(float x, float y)
//�Լ� �������̵� (����� Ư���� ��� ���)
//void Text::append(string _extra)
//void Fancy::append(string _extra)

class Text {
private:
	string text;
public:
	Text(string _t) : text(_t) {}
	virtual string get() { return text; }
	virtual void append(string _extra) { text += _extra; }
};

class FancyText : public Text {
private:
	//string text; ������ �ȵ�, Base class���� private�̱� ����
	string left_brac;
	string right_brac;
	string connector;
public:
	//initialization list�� �����ڸ� ȣ���� �� �ְ� ���� (�θ�class������ Text::Text(_t)ȣ��
	FancyText(string _t, string _lb, string _rb, string _con)
		: Text::Text(_t), left_brac(_lb), right_brac(_rb), connector(_con) {}
	string get() override { return left_brac + Text::get() + right_brac; }
	void append(string _extra) override { Text::append(connector + _extra); }
};

class FixedText : public Text {
public:
	FixedText() : Text::Text("FIXED") {} //FixedText class�� ������ �ȿ��� Text class�� ������ Text ȣ��
	void append(string _extra) override { 
		//NO OPERATION 
	}
};

int main() {
	Text t1("Plain");
	t1.append("A");
	cout << t1.get() << endl;

	FancyText t2("Fancy", "<<", ">>", "***");
	t2.append("A");
	cout << t2.get() << endl;

	FixedText t3;
	t3.append("A");
	cout << t3.get() << endl;
	t1 = t2; // Base <- Derived ����
//	t2 = t1; // Derived <- Based �Ұ���

	return 0;
}