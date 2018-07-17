//第十章第2题
#include <iostream>

using namespace std;

class Complex {
	private:
		double real;
		double imag;
	public:
		Complex(double, double);
		Complex operator +(const Complex&);
		Complex operator -(const Complex&);
		Complex operator *(const Complex&);
		Complex operator /(const Complex&);
		void show();
};

Complex::Complex(double x = 0, double y = 0) {
	real = x;
	imag = y;
}

Complex Complex::operator +(const Complex& c) {
	return Complex(real + c.real, imag + c.imag);
}

Complex Complex::operator -(const Complex& c) {
	return Complex(real - c.real, imag - c.imag);
}

Complex Complex::operator *(const Complex& c) {
	return Complex(real * c.real - imag * c.imag, imag * c.real + real * c.imag);
}

Complex Complex::operator /(const Complex& c) {
	return Complex((real * c.real + imag * c.imag) / (c.real * c.real + c.imag * c.imag), (imag * c.real - real * c.imag) / (c.real * c.real + c.imag * c.imag));
}

void Complex::show() {
	if (imag > 0) {
		cout << "(" << real << "+" << imag << "i" << ")" << endl;
	} else {
		cout << "(" << real << imag << "i" << ")" << endl;
	}
}

int main() {
	Complex c1(5, 6), c2(3, 4);
	Complex c3;
	(c1 + c2).show();
	(c1 - c2).show();
	(c1 * c2).show();
	(c1 / c2).show();
	return 0;
}
