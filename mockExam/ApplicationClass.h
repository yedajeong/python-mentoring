#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Item {
protected:
	string code;
	string name;
	string price;
public:
	Item() {}
	Item(string _code, string _name, string _price) {}

	virtual void displayItem() const {
		cout << code << setw(10) << name << setw(10) << price << setw(10) << endl;
	}
	virtual int readItemFromFile(ifstream& _fin) {
		return 0;
	}
	virtual int writeItemToFile(ofstream& _fout) {
		return 0;
	}

	friend class ApplicationClass;
};

class FoodItem : public Item {
private:
	int dueDate; //유통기한
public:
	FoodItem(int _dueDate = 0) {}

	void displayItem() const override {
		cout << code << setw(10) << name << setw(10) << price << setw(10) << dueDate << endl;
	}
	virtual int readItemFromFile(ifstream& _fin) override {
		if (!_fin.eof())
			_fin >> code >> name >> price >> dueDate;
		else
			return 0;
		return 1;
	}
	virtual int writeItemToFile(ofstream& _fout) override {
		if (_fout.is_open())
			_fout << code << setw(10) << name << setw(10) << price << setw(10) << dueDate << endl;
		else
			return 0;
		return 1;
	}

	friend class ApplicationClass;
};

class OfficeItem : public Item {
private:
	string company; //제조사
public:
	OfficeItem(string _company = "") {}
	virtual void displayItem() const override {
		cout << code << setw(10) << name << setw(10) << price << setw(10) << company << endl;
	}
	virtual int readItemFromFile(ifstream& _fin) override {
		if (!_fin.eof())
			_fin >> code >> name >> price >> company;
		else
			return 0;
		return 1;
	}
	virtual int writeItemToFile(ofstream& _fout) override {
		if (_fout.is_open())
			_fout << code << setw(10) << name << setw(10) << price << setw(10) << company << endl;
		else
			return 0;
		return 1;
	}

	friend class ApplicationClass;
};

class ApplicationClass {
private:
	vector<Item*> vItem; //아이템들의 배열
	string officeItemFileName; //사무용품 정보가 저장된 파일
	string foodItemFileName; //식품 정보가 저장된 파일
public:
	ApplicationClass(string _officeItemFileName, string _foodItemFileName);
	void displayAllItems();
	void displayFoodItems();
	void displayOfficeItems();
	void searchItemByCode();
	void run();
	string getCommand();
};

