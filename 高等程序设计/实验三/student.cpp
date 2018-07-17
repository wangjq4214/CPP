#include <iostream>
#include "student.h"

using std::cout;
using std::cin;
using std::endl;

void Student::set() {
	People::set();
	cout << "ÇëÊäÈë°àºÅ£º" << endl;
	cin >> classNO;
}

void Student::display() {
	People::display();
	cout << "°àºÅ£º" << classNO << endl;
}
