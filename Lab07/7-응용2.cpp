#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

//���� 02
int main() {
	string data = "���,���α׷���,����,����ǹٺ�,���뿪,õ���ǻ��,�����,��ü����";
	string keyWord, word;
	int commaIndex, wordIndex = 0;

	cout << "Ű���� : ";
	cin >> keyWord;

	cout << "�˻���� : ";

/*
	//Ǯ�� 1
	while (data.find(keyWord) != string::npos) {
		commaIndex = data.find(",");
		word = data.substr(0, commaIndex);
		if (word.find(keyWord) != string::npos)
			cout << word << "  ";
		data = data.substr(commaIndex + 1);
	}
	*/
	
	//Ǯ�� 2
	while (data.find(keyWord,wordIndex) != string::npos) {
		commaIndex = data.find(",", wordIndex);
		word = data.substr(wordIndex, (commaIndex - wordIndex));
		wordIndex = commaIndex + 1;

		if (word.find(keyWord) != string::npos)
			cout << word << "  ";
		else
			continue;
		
	}
	return 0;
}
