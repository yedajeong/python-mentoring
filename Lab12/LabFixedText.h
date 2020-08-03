#pragma once
#include "LabText.h"

//03
class FixedText : public Text {
public:
	FixedText();
	void append(string _extra) override;
	//get함수는 Text클래스에서와 기능 같음
};
