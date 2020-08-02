#include <iostream>
#include <string>
using namespace std;

//����01

class Polygon {
public:
	Polygon() {}
	Polygon(int point, float length) { mPoint = point; mLength = length; }
	~Polygon() {}
	virtual void calcPerimeter() { cout << "Perimeter: empty" << endl; }
	virtual void calcArea() { cout << "Area: empty" << endl; }
protected:
	int mPoint; //�������� ����
	double mLength; //�� ���� ����
};

class Rectangle : public Polygon {
public:
	Rectangle() {}
	Rectangle(int point, float length) :Polygon::Polygon(point, length) {}
	~Rectangle() {}
	void calcPerimeter() override {
		double result = 4 * this->mLength;
		cout << "Perimeter: " << result << endl;
	}
	void calcArea() override {
		double result = this->mLength * this->mLength;
		cout << "Area: " << result << endl;
	}
};

int main() {
	Polygon pol;
	Rectangle rec(4, 10);

	cout << "--- Polygon class ---" << endl;
	pol.calcPerimeter();
	pol.calcArea();
	cout << "--- Rectangle class ---" << endl;
	rec.calcPerimeter();
	rec.calcArea();

	return 0;
}