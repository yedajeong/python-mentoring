#pragma once
#include "LabText.h"

//03
class FixedText : public Text {
public:
	FixedText();
	void append(string _extra) override;
	//get�Լ��� TextŬ���������� ��� ����
};
