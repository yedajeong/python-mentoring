#include "ApplicationClass.h"
using namespace std;

int main() {
	ApplicationClass appManager("foodItem.txt", "officeItem.txt");
	appManager.run();

	return 0;
}