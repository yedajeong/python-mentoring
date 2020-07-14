#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Item {
private:
	string code;
	string name;
	int price;
public:
	Item(string _code, string _name, int _price) :
		code(_code), name(_name), price(_price) {}

	Item() {
		code = "";
		name = "";
		price = 0;
	}

	string getCode() { return code; }
	string getName() { return name; }
	int getPrice() { return price; }

	void setCode(string _code) { code = _code; }
	void setName(string _name) { name = _name; }
	void setPrice(int _price) { price = _price; }
};

int main() {
	Item item1("C1001", "계산기", 14000);
	Item item2;
	item2.setCode("F1002");
	item2.setName("계란빵");
	item2.setPrice(1000);

	cout << item1.getCode() << setw(10) << item1.getName() << setw(10) << item1.getPrice() << endl;
	cout << item2.getCode() << setw(10) << item2.getName() << setw(10) << item2.getPrice() << endl;

	return 0;
}