#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

//응용 02
int main() {
	string data = "사랑,프로그래밍,의자,사랑의바보,영통역,천년의사랑,냉장고,객체지향";
	string keyWord, word;
	int commaIndex, wordIndex = 0;

	cout << "키워드 : ";
	cin >> keyWord;

	cout << "검색결과 : ";

/*
	//풀이 1
	while (data.find(keyWord) != string::npos) {
		commaIndex = data.find(",");
		word = data.substr(0, commaIndex);
		if (word.find(keyWord) != string::npos)
			cout << word << "  ";
		data = data.substr(commaIndex + 1);
	}
	*/
	
	//풀이 2
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
