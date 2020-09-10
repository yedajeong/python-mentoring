#include <iostream>
#include <vector>
using namespace std;

//응용04
int main() {
	int input;
	cout << "홀수 숫자 하나를 입력해주세요 : ";
	cin >> input;
	vector<vector<int>> v(input, vector<int>(input, 0));
	int hang = 0;
	int yul = (input - 1) / 2;
	v[hang][yul] = 1; //1의 위치는 0행 가운데

	for (int i = 1; i < input*input; i++) {
		hang--;
		yul++; //현재 위치에서 오른쪽 대각선 칸으로 위치 이동
		if (hang < 0) {
			hang += input; //행의 index가 -1(0행보다 위)이면 +input해서 제일 아래 행으로
			if (yul > input-1) {
				yul -= input; //열의 index가 input([input-1]열보다 오른쪽)이면 -input해서 제일 왼쪽 열로
				if (v[hang][yul] != 0) {
					hang = hang - (input-1);
					yul += (input-1); //현재 위치에 0(초기화)이 아니라 다른 수가 있으면 다시 원래 칸(i위치)으로 복귀
					hang++; //복귀한 (i위치)의 아래 행에 (i+1)이 위치함
				}
			}
			else if (v[hang][yul] != 0) {
				hang = hang - (input-1);
				yul--; //현재 위치에 0(초기화)이 아니라 다른 수가 있으면 다시 원래 칸(i위치)으로 복귀
				hang++; //복귀한 (i위치)의 아래 행에 (i+1)이 위치함
			}
		}

		else if (yul > input-1) {
			yul -= input; //열의 index가 input([input-1]열보다 오른쪽)이면 -input해서 제일 왼쪽 열로
			if (v[hang][yul] != 0) {
				hang++;
				yul += (input-1); //현재 위치에 0(초기화)이 아니라 다른 수가 있으면 다시 원래 칸(i위치)으로 복귀
				hang++; //복귀한 (i위치)의 아래 행에 (i+1)이 위치함
			}
		}

		else if (v[hang][yul] != 0) {
			hang += 2;
			yul--; //현재 위치에 0(초기화)이 아니라 다른 수가 있으면 다시 원래 칸으로 복귀, 그 칸의 아래 행으로
		}

		v[hang][yul] = i + 1; //숫자+1 그 칸에 위치
	}

	for (int i = 0; i < input; i++) {
		for (int j = 0; j < input; j++)
			cout << "\t" << v[i][j];
		cout << endl;
	}

	return 0;
}