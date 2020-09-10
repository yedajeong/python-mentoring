#include <iostream>
#include <vector>
using namespace std;

//응용02
int main() {
	vector<int> list;
	int size = rand() % 100 + 1;
	for (int i = 0; i < size; i++) {
		list.push_back(i);
	}

	int cnt = -1;
	while (1) {
		cnt++;
		try {
			list.at(cnt);
		}
		catch (exception& e) {
			cout << "현재 list는 " << cnt << "의 크기를 가지고 있다" << endl;
			exit(100);
		}
	}

	return 0;
}