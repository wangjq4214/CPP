#include <iostream>

using namespace std;

class Shape {
	public:
		virtual double area()  = 0;
};

class Circle:public Shape {
	public:
		Circle(double r):radius(r) {}
		virtual double area() {
			return 3.1415926 * radius * radius;
		};
	protected:
		double radius;
};

class Rectangle:public Shape {
	public:
		Rectangle(double w, double h):width(w),height(h) {}
		virtual double area() {
			return width * height;
		}
	protected:
		double width, height;
};

class Triangle:public Shape {
	public:
		Triangle(double w, double h):width(w), height(h) {}
		virtual double area() {
			return 0.5 * width * height;
		}
	protected:
		double width, height;
};

void printArea(Shape &s) {
	cout << s.area() << endl;
}

int main() {
	Circle circle(2.6);
	cout << "area of circle=";
	printArea(circle);
	Rectangle rectangle(4,8.4);
	cout << "area of rectangle=";
	printArea(rectangle);
	Triangle triangle(4.5,8.4);
	cout << "area of triangle=";
	printArea(triangle);
	return 0;
}
