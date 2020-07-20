#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

class Item {
protected:
	string code;
	string name;
	int price;
public:
	Item(string _code, string _name, int _price);
	Item();

	virtual void displayItem() const;

	virtual int readItemFromFile(ifstream& fin);
	virtual int writeItemToFile(ofstream& fout);
};

