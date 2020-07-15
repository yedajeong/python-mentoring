#pragma once
#include "CItem.h"

class OfficeItem : public Item {
private:
	string company;
public:
	OfficeItem(string _company = "");

	void displayItem() const override;

	int readItemFromFile(ifstream& fin) override;

	int writeItemToFile(ofstream& fout) override;
};

