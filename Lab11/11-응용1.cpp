#include <iostream>
#include <cmath>
using namespace std;

//����01
class Point {
private:
	int x;
	int y;
public:
	Point() : x(0), y(0) {}

	Point(int _x, int _y) { //int _x�� int _y�� �Է����� �޴� ������
		x = _x;
		y = _y;
	}

	~Point() { /*cout << "Destructed..." << endl;*/ } //�Ҹ���

	void setPoint(int _x, int _y) { //this-> ����� �ʱ�ȭ
		this->x = _x;
		this->y = _y;
	}

	int getX() const { return x; }
	int getY() const { return y; }

	Point operator-(const Point& pt) {
		Point result(this->x - pt.x, this->y - pt.y);
		return result;
	}

	Point operator*(const Point& pt) { //�� -���� const�Ⱥٿ��� �Ǹ鼭 *���� const�ٿ��� ���� �������..
		Point result(this->x * pt.x, this->y * pt.y);
		return result;
	}

};
int main() {
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	Point* pP1, *pP2, *pP3;

	cout << "ù��° ��ǥ(x1, y1)�� �Է��ϼ��� : ";
	cin >> x1 >> y1;

	cout << "�ι�° ��ǥ(x2, y2)�� �Է��ϼ��� : ";
	cin >> x2 >> y2;

	pP1 = new Point(x1, y1);
	pP2 = new Point(x2, y2);
	pP3 = new Point(); //x, y�� 0���� �ʱ�ȭ

	/*�Ʒ��� ������ε� x, y�� ������ �����ؾ� ��*/
	//pP1->setPoint(x1, y1);
	//pP2->setPoint(x2, y2);

	*pP3 = (*pP1 - *pP2) * (*pP1 - *pP2);

	/*pP3�� Ȱ���Ͽ� �Ÿ����� ����*/
	cout << "�� ��ǥ ������ ���̴� " << sqrt(pP3->getX() + pP3->getY()) << "�Դϴ�." << endl;

	return 0;
}