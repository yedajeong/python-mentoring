#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
using namespace std;

//ÀÀ¿ë 03
int main() {
	ofstream fout("temp.txt");

	if (!fout) {
		cout << "Error" << endl;
		exit(100);
	}

	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			fout.width(4);
			fout << rand() % 101;
		}
		fout << endl;
	}
	
	fout.close();

	cout << "end";

	return 0;
}