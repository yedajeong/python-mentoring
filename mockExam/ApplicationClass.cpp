#include "ApplicationClass.h"

ApplicationClass::ApplicationClass(string _foodItemFileName, string _officeItemFileName)
	: foodItemFileName(_foodItemFileName), officeItemFileName(_officeItemFileName) {

	Item* pItem = new FoodItem;
	ifstream fin(foodItemFileName);
	while (pItem->readItemFromFile(fin)) {
		vItem.push_back(pItem);
		pItem = new FoodItem;
	}
	fin.close();

	Item* pItem2 = new OfficeItem;
	ifstream fin2(officeItemFileName);
	while (pItem2->readItemFromFile(fin2)) {
		vItem.push_back(pItem2);
		pItem2 = new OfficeItem;
	}
	fin2.close();
}

void ApplicationClass::displayAllItems() {
	for (auto& elem : vItem) 
		elem->displayItem();
}
void ApplicationClass::displayFoodItems() {
	for (auto& elem : vItem) 
		if(elem->code[0] == 'F')
			elem->displayItem();
}
void ApplicationClass::displayOfficeItems() {
	for (auto& elem : vItem)
		if (elem->code[0] == 'C')
			elem->displayItem();
}
void ApplicationClass::searchItemByCode() {
	string userInputCode;
	bool flag = true;
	cout << "Enter the code: ";
	cin >> userInputCode;
	for (auto& elem : vItem) {
		if (elem->code == userInputCode){
			elem->displayItem();
			flag = false;
		}
	}
	if (flag == true)
		cout << "No items found." << endl;
}

string ApplicationClass::getCommand() {
	string userInput;
	cout << "1. Display all items." << endl;
	cout << "2. Display food items." << endl;
	cout << "3. Display office items." << endl;
	cout << "4. Search item by code." << endl;
	cout << "5. Quit." << endl;
	cout << "Input>";
	cin >> userInput;
	return userInput;
}

void ApplicationClass::run() {
	string sOption;
	while (1) {
		sOption = getCommand();
		if (sOption == "1") displayAllItems();
		else if (sOption == "2") displayFoodItems();
		else if (sOption == "3") displayOfficeItems();
		else if (sOption == "4") searchItemByCode();
		else if (sOption == "5") break;
	}
	cout << "Exit the program..." << endl;
}