#include "CFoodItem.h"

FoodItem::FoodItem(int _dueDate) :
		dueDate(_dueDate) {}

void FoodItem::displayItem() const {
	cout << code << setw(10) << name << setw(10) << price << setw(10) << dueDate << "\n";
}

int FoodItem::readItemFromFile(ifstream& fin) {
	if (!fin.eof()) {
		fin >> code >> name >> price >> dueDate;
		return 1;
	}
	return 0;
}

int FoodItem::writeItemToFile(ofstream& fout) {
	if (fout.is_open()) {
		fout << code << setw(10) << name << setw(10) << price << setw(10) << dueDate << "\n";
		return 1;
	}
	return 0;
}