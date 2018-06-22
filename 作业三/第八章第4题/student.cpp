#include <iostream>
#include "student.h"

using std::cin;
using std::cout;
using std::endl;

void student::set_value() {
	cin >> num >> name >> sex;
}

void student::display() {
	cout << "num:" << num << endl;
	cout << "name:" << name << endl;
	cout << "sex:" << sex << endl;
}
