#pragma once
#include "LabText.h"

//03
class FancyText : public Text {
private:
	string left_brac;
	string right_brac;
	string connector;
public:
	FancyText(string _t, string _lb, string _rb, string _con);
	string get() override;
	void append(string _extra) override;
};