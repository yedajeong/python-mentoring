#include <iostream>
#include <string>
using namespace std;

//02

//함수 오버로딩 : int    sum(int x, int y)
//				 double sum(double x, double y)
//				 float  sum(float x, float y)
//함수 오버라이딩 (상속의 특수한 경우 사용)
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
	//string text; 접근이 안됨, Base class에서 private이기 때문
	string left_brac;
	string right_brac;
	string connector;
public:
	//initialization list는 생성자를 호출할 수 있게 해줌 (부모class생성자 Text::Text(_t)호출
	FancyText(string _t, string _lb, string _rb, string _con)
		: Text::Text(_t), left_brac(_lb), right_brac(_rb), connector(_con) {}
	string get() override { return left_brac + Text::get() + right_brac; }
	void append(string _extra) override { Text::append(connector + _extra); }
};

class FixedText : public Text {
public:
	FixedText() : Text::Text("FIXED") {} //FixedText class의 생성자 안에서 Text class의 생성자 Text 호출
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
	t1 = t2; // Base <- Derived 가능
//	t2 = t1; // Derived <- Based 불가능

	return 0;
}