#include "COfficeItem.h"

OfficeItem::OfficeItem(string _company) :
		company(_company) {}

void OfficeItem::displayItem() const {
	cout << code << setw(10) << name << setw(10) << price << setw(10) << company << "\n";
}

int OfficeItem::readItemFromFile(ifstream& fin) {
	if (!fin.eof()) {
		fin >> code >> name >> price >> company;
		return 1;
	}
	return 0;
}

int OfficeItem::writeItemToFile(ofstream& fout) {
	if (fout.is_open()) {
		fout << code << setw(10) << name << setw(10) << price << setw(10) << company << "\n";
		return 1;
	}
	return 0;
}
