#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

class Item {
private:
	string code;
	string name;
	int price;
public:
	Item(string _code, string _name, int _price) :
		code(_code), name(_name), price(_price) {}

	Item() {}

	string getCode() { return code; }
	string getName() { return name; }
	int getPrice() { return price; }

	void setCode(string _code) { code = _code; }
	void setName(string _name) { name = _name; }
	void setPrice(int _price) { price = _price; }
	void setItem(string _code, string _name, int _price) {
		code = _code;
		name = _name;
		price = _price;
	}

	bool readItemFromFile(ifstream& fin) {
		if (!fin.eof()) {
			fin >> code >> name >> price;
			return true;
		}
		else
			return false;
	}

	bool writeItemToFile(ofstream& fout) {
		if (fout.is_open()) {
			fout << code << "\t" << name << "\t" << price << endl;
			return true;
		}
		else
			return false;
		
	}
};

int main() {
	Item temp;
	vector<Item> vItem;
	string inFleName = "item.txt";
	string outFleName = "item_output.txt";

	ifstream fin;
	fin.open(inFleName);
	while (temp.readItemFromFile(fin))
		vItem.push_back(temp);
	fin.close();

	temp.setItem("E1002", "¹ÚÄ«½º", 1000);
	vItem.push_back(temp);

	ofstream fout;
	fout.open(outFleName);
	for (auto elem : vItem)
		elem.writeItemToFile(fout);
	fout.close();

	return 0;
}