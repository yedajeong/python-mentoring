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
	int dueDate; //�������
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
	string company; //������
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
	vector<Item*> vItem; //�����۵��� �迭
	string officeItemFileName; //�繫��ǰ ������ ����� ����
	string foodItemFileName; //��ǰ ������ ����� ����
public:
	ApplicationClass(string _officeItemFileName, string _foodItemFileName);
	void displayAllItems();
	void displayFoodItems();
	void displayOfficeItems();
	void searchItemByCode();
	void run();
	string getCommand();
};

