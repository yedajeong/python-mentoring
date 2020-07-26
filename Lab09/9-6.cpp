#include <iostream>
#include <iomanip>
using namespace std;

//06
bool found_char(const char *s, char ch) {
	while (*s != '\0') {
		if (*s == ch)
			return true;
		s++;
	}
	return false;
}

int main() {
	//					012345(6)
	const char *phrase = "phrase"; //ch[]
								   //phrase(\0)==NULL
	
	for (char ch = 'a'; ch <= 'z'; ch++) { //'a'==65, 'z'==97
		cout << ch << " is ";
		if (!found_char(phrase, ch)) //found_char이 false면 NOT출력
			cout << "NOT ";
		cout << "in (" << phrase << ")" << endl;
	}

	return 0;
}