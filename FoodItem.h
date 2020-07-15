#pragma once
#include "CItem.h"

class FoodItem : public Item {
private:
	int dueDate;
public:
	FoodItem(int _dueDate = 0);

	void displayItem() const override;

	int readItemFromFile(ifstream& fin) override;

	int writeItemToFile(ofstream& fout) override;
};
