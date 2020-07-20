#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include "CFoodItem.h"
#include "COfficeItem.h"
using namespace std;

int main() {
	vector<Item*> vItem;
	Item* pItem = new FoodItem;
	ifstream fin1("foodItem.txt");
	while (pItem->readItemFromFile(fin1)) {
		vItem.push_back(pItem);
		pItem = new FoodItem;
	}
		

	pItem = new OfficeItem;
	ifstream fin2("officeItem.txt");
	while (pItem->readItemFromFile(fin2)) {
		vItem.push_back(pItem);
		pItem = new OfficeItem;
	}
		

	for (auto& elem : vItem)
		elem->displayItem();

	return 0;
}