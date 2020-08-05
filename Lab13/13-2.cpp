#include <iostream>
using namespace std;

//02
template<class T>
class Point {
private:
	T x;
	T y;
public:
	Point(T _x, T _y);
	void setXY(T _x, T _y);
	T getX();
	T gexY();
	void print();
};

template<class T>
Point<T>::Point(T _x, T _y) : x(_x), y(_y) {}

template<class T>
void Point<T>::setXY(T _x, T _y) {
	x = _x;
	y = _y; 
}

template<class T>
T Point<T>::getX() { return x; }

template<class T>
T Point<T>::gexY() { return y; }

template<class T>
void Point<T>::print() { cout << x << ", " << y << endl; }

int main() {
	Point<int> pt1(1, 2);
	Point<double> pt2(1.1, 2.2);
	pt1.print();
	pt2.print();

	return 0;
}