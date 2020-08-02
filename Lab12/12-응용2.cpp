#include <iostream>
#include <string>
using namespace std;

//응용02

class Polygon {
public:
	Polygon() {}
	Polygon(int point, float length) { mPoint = point; mLength = length; }
	~Polygon() {}
	virtual void calcPerimeter() { cout << "Perimeter: empty" << endl; }
	virtual void calcArea() { cout << "Area: empty" << endl; }
protected:
	int mPoint; //꼭짓점의 개수
	double mLength; //한 변의 길이
};

class Rectangle : public Polygon {
public:
	Rectangle() {}
	Rectangle(int point, float length) :Polygon::Polygon(point, length) {}
	~Rectangle() {}
	void calcPerimeter() override {
		float result;
		result = this->mPoint * this->mLength;
		cout << "Perimeter: " << result << endl;
	}
	void calcArea() override {
		float result;
		result = this->mLength * this->mLength;
		cout << "Area: " << result << endl;
	}
};

class Triangle : public Polygon {
public:
	Triangle() {}
	Triangle(int point, float length) :Polygon::Polygon(point, length) {}
	~Triangle() {}
	void calcPerimeter() override {
		float result;
		result = this->mPoint * this->mLength;
		cout << "Perimeter: " << result << endl;
	}
	void calcArea() override {
		double result;
		result = this->mLength * this->mLength * 0.5 * 0.866026; //sin60 = 0.866026
		cout << "Area: " << result << endl;
	}
};

class Circle : public Polygon {
public:
	Circle() {}
	Circle(int point, float length) :Polygon::Polygon(point, length) {}
	~Circle() {}
	void calcPerimeter() override {
		float result;
		result = 2 * 3.14 * this->mLength;
		cout << "Perimeter: " << result << endl;
	}
	void calcArea() override {
		float result;
		result = this->mLength * this->mLength * 3.14;
		cout << "Area: " << result << endl;
	}
};

int main() {
	Triangle tri(3, 10);
	Rectangle rec(4, 10);
	Circle cir(0, 5);

	cout << "--- Triangle class ---" << endl;
	tri.calcPerimeter();
	tri.calcArea();

	cout << "--- Rectangle class ---" << endl;
	rec.calcPerimeter();
	rec.calcArea();

	cout << "--- Circle class ---" << endl;
	cir.calcPerimeter();
	cir.calcArea();

	return 0;
}