#include <iostream>
#include "student.h"

using std::cout;
using std::cin;
using std::endl;

void Student::set() {
	People::set();
	cout << "�������ţ�" << endl;
	cin >> classNO;
}

void Student::display() {
	People::display();
	cout << "��ţ�" << classNO << endl;
}
