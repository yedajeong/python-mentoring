#include <iostream>
using namespace std;

//01
class Point {
private:
	int x;
	int y;
	static int numCreatedObjects;
public:
	Point() : x(0), y(0) { numCreatedObjects++; } //initializtion list이용한 default생성자

	Point(int _x, int _y) { //int _x와 int _y를 입력으로 받는 생성자
		x = _x;
		y = _y;
		numCreatedObjects++;
	}

	~Point() { cout << "Destructed..." << endl; } //소멸자

	void setXY(int _x, int _y) { //this-> 사용한 초기화
		this->x = _x;
		this->y = _y;
	}

	int getX() const { return x; }
	int getY() const { return y; }

	//*this + pt2 ->
	Point operator+(Point& pt2) {
		Point result(this->x + pt2.x, this->y + pt2.y);
		return result;
	}

	//operator overloading(연산자 오버로딩)
	Point& operator=(Point& pt) {
		this->x = pt.x;
		this->y = pt.y;
		return (*this);
	}

	static int getNumCreatedObject() { return numCreatedObjects; }
	friend void print(const Point& pt);
	friend ostream& operator<<(ostream& cout, Point& pt);
	friend class SpyPoint;
};

//static 멤버 변수 초기화 (numCreatedObjects)
int Point::numCreatedObjects = 0;

//객체 call by ref.시: const로 함수 입력시 const method만 함수에서 사용가능
//const: 객체 내부의 member data가 상수(변하지 않는다)
void print(const Point& pt) {
	cout << pt.x << ", " << pt.y << endl;
}

//Point operator+(Point& pt1, Point& pt2) {
//	Point result(pt1.getX() + pt2.getX(), pt1.getY() + pt2.getY());
//	return result;
//}

ostream& operator<<(ostream& cout, Point& pt) {
	cout << pt.getX() << ", " << pt.getY();
	return cout;
}

class SpyPoint {
public:
	void hack_point_info(const Point& pt) {
		cout << "Hacked by SpyPoint" << endl;
		cout << "x: " << pt.getX() << endl << "y: " << pt.getY() << endl << "numCreatedObj.: " << pt.getNumCreatedObject() << endl <<endl;
	}
};

int main() {
	Point pt1(1, 2);
	cout << "pt1 : ";
	print(pt1);
	cout << endl;

	//포인터
	Point* pPt1 = &pt1;
	//pPt1의 값을 통해 getX, getY를 호출하여 출력
	cout << "pt1 : ";
	cout<< (*pPt1).getX() << ", " << (*pPt1).getY() << endl;
	//pPt1를 통해 호출 getX, getY를 호출하여 출력
	cout << "pt1 : ";
	cout << pPt1->getX() << ", " << pPt1->getY() << endl;

	cout << endl;

	//동적으로 Point* pPt2할당하여 10,20넣은 뒤 ->사용하여 출력
	Point* pPt2 = new Point(10, 20);
	cout << "pt2 : ";
	cout << pPt2->getX() << ", " << pPt2->getY() << endl;

	cout << endl;

	//pPt1, pPt2의 메모리 해제
	pPt1->~Point();
	delete pPt2;

	cout << "pt1 NumCreatedObject : ";
	cout << pt1.getNumCreatedObject() << endl;

	//연산자 오버로딩
	//pt4 = pt2, pt3값 더하기
	Point pt3(30, 40);
	Point pt2(10, 20);
	Point pt4 = pt2 + pt3;
	cout << "pt2 : ";
	cout << pt2 << endl;
	cout << "pt3 : ";
	cout << pt3 << endl;
	cout << "pt4 : ";
	cout << pt4 << endl;

	cout << "pt1 NumCreatedObject : ";
	cout << pt1.getNumCreatedObject() << endl << endl;

	//object array
	Point* ptAry = new Point[5];
	cout<<"pt2 NumCreatedObject : ";
	cout << pt2.getNumCreatedObject() << endl;
	cout << endl;

	//ptAry 메모리 해제
	delete[] ptAry;

	cout << endl;

	//friend class
	SpyPoint spy;
	cout << "pt1 info" << endl;
	spy.hack_point_info(pt1);
	cout << "pt4 info" << endl;
	spy.hack_point_info(pt4);

	return 0;
}
