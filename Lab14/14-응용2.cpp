#include <iostream>
#include <vector>
using namespace std;

//����02
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
			cout << "���� list�� " << cnt << "�� ũ�⸦ ������ �ִ�" << endl;
			exit(100);
		}
	}

	return 0;
}