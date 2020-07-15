#include "CItem.h"

Item::Item(string _code, string _name, int _price) :
		code(_code), name(_name), price(_price) {}

Item::Item() {}

void Item::displayItem() const {
	cout << code << setw(10) << name << setw(10) << price << setw(10) << "\n";
}

int Item::readItemFromFile(ifstream& fin) { return 0; }
int Item::writeItemToFile(ofstream& fout) { return 0; }