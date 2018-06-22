#include <iostream>
#include <string>

using namespace std;

class Teacher {
	public:
		Teacher(int, string, char);
		void display();
	private:
		int num;
		string name;
		char sex;
};

Teacher::Teacher(int n, string nam, char s) {
	num = n;
	name = nam;
	sex = s;
}

void Teacher::display() {
	cout << "num:" << num << endl;
	cout << "name:" << name << endl;
	cout << "sex:" << sex << endl;
}

class BirthDate {
	public:
		BirthDate(int, int, int);
		void display();
		void change(int, int, int);
	private:
		int year;
		int month;
		int day;
};

BirthDate::BirthDate(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
}

void BirthDate::display() {
	cout << "birthday:" << year << "/" << month << "/" << day << endl;
}

void BirthDate::change(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
}

class Professor:public Teacher {
	public:
		Professor(int, string, char, int, int, int, float);
		void display();
		void change(int, int, int);
	private:
		float area;
		BirthDate birthday;
};

Professor::Professor(int n, string nam, char s, int y, int m, int d, float a):
	Teacher(n, nam, s), birthday(y, m, d), area(a) {}

void Professor::display() {
	Teacher::display();
	birthday.display();
	cout << "area:" << area << endl;
}

void Professor::change(int y, int m, int d) {
	birthday.change(y, m, d);
}

int main() {
	Professor prof1(3012,"Zhang",'f',1949,10,1,125.4);
	cout << "original data:" << endl;
	prof1.display();
	cout << "new data:" << endl;
	prof1.change(1950, 6, 1);
	prof1.display();
	return 0;
}
