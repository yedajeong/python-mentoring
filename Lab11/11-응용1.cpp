#include <iostream>
#include <cmath>
using namespace std;

//응용01
class Point {
private:
	int x;
	int y;
public:
	Point() : x(0), y(0) {}

	Point(int _x, int _y) { //int _x와 int _y를 입력으로 받는 생성자
		x = _x;
		y = _y;
	}

	~Point() { /*cout << "Destructed..." << endl;*/ } //소멸자

	void setPoint(int _x, int _y) { //this-> 사용한 초기화
		this->x = _x;
		this->y = _y;
	}

	int getX() const { return x; }
	int getY() const { return y; }

	Point operator-(const Point& pt) {
		Point result(this->x - pt.x, this->y - pt.y);
		return result;
	}

	Point operator*(const Point& pt) { //왜 -에는 const안붙여도 되면서 *에는 const붙여야 에러 사라질까..
		Point result(this->x * pt.x, this->y * pt.y);
		return result;
	}

};
int main() {
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	Point* pP1, *pP2, *pP3;

	cout << "첫번째 좌표(x1, y1)를 입력하세요 : ";
	cin >> x1 >> y1;

	cout << "두번째 좌표(x2, y2)를 입력하세요 : ";
	cin >> x2 >> y2;

	pP1 = new Point(x1, y1);
	pP2 = new Point(x2, y2);
	pP3 = new Point(); //x, y가 0으로 초기화

	/*아래의 방식으로도 x, y값 설정이 가능해야 함*/
	//pP1->setPoint(x1, y1);
	//pP2->setPoint(x2, y2);

	*pP3 = (*pP1 - *pP2) * (*pP1 - *pP2);

	/*pP3을 활용하여 거리값을 구함*/
	cout << "두 좌표 사이의 길이는 " << sqrt(pP3->getX() + pP3->getY()) << "입니다." << endl;

	return 0;
}