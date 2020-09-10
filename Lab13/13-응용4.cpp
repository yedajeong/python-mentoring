#include <iostream>
#include <vector>
using namespace std;

//����04
int main() {
	int input;
	cout << "Ȧ�� ���� �ϳ��� �Է����ּ��� : ";
	cin >> input;
	vector<vector<int>> v(input, vector<int>(input, 0));
	int hang = 0;
	int yul = (input - 1) / 2;
	v[hang][yul] = 1; //1�� ��ġ�� 0�� ���

	for (int i = 1; i < input*input; i++) {
		hang--;
		yul++; //���� ��ġ���� ������ �밢�� ĭ���� ��ġ �̵�
		if (hang < 0) {
			hang += input; //���� index�� -1(0�ຸ�� ��)�̸� +input�ؼ� ���� �Ʒ� ������
			if (yul > input-1) {
				yul -= input; //���� index�� input([input-1]������ ������)�̸� -input�ؼ� ���� ���� ����
				if (v[hang][yul] != 0) {
					hang = hang - (input-1);
					yul += (input-1); //���� ��ġ�� 0(�ʱ�ȭ)�� �ƴ϶� �ٸ� ���� ������ �ٽ� ���� ĭ(i��ġ)���� ����
					hang++; //������ (i��ġ)�� �Ʒ� �࿡ (i+1)�� ��ġ��
				}
			}
			else if (v[hang][yul] != 0) {
				hang = hang - (input-1);
				yul--; //���� ��ġ�� 0(�ʱ�ȭ)�� �ƴ϶� �ٸ� ���� ������ �ٽ� ���� ĭ(i��ġ)���� ����
				hang++; //������ (i��ġ)�� �Ʒ� �࿡ (i+1)�� ��ġ��
			}
		}

		else if (yul > input-1) {
			yul -= input; //���� index�� input([input-1]������ ������)�̸� -input�ؼ� ���� ���� ����
			if (v[hang][yul] != 0) {
				hang++;
				yul += (input-1); //���� ��ġ�� 0(�ʱ�ȭ)�� �ƴ϶� �ٸ� ���� ������ �ٽ� ���� ĭ(i��ġ)���� ����
				hang++; //������ (i��ġ)�� �Ʒ� �࿡ (i+1)�� ��ġ��
			}
		}

		else if (v[hang][yul] != 0) {
			hang += 2;
			yul--; //���� ��ġ�� 0(�ʱ�ȭ)�� �ƴ϶� �ٸ� ���� ������ �ٽ� ���� ĭ���� ����, �� ĭ�� �Ʒ� ������
		}

		v[hang][yul] = i + 1; //����+1 �� ĭ�� ��ġ
	}

	for (int i = 0; i < input; i++) {
		for (int j = 0; j < input; j++)
			cout << "\t" << v[i][j];
		cout << endl;
	}

	return 0;
}