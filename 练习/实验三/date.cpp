#include <iostream>
#include "date.h"

using std::cout;
using std::cin;
using std::endl;

Date::Date() {
	yyyy = 0;
	mm = 0;
	dd = 0;
}

void Date::set() {
	cout << "������������ڣ��Կո����֣���" << endl; 
	cin >> yyyy >> mm >> dd;
}

void Date::display() {
	cout << "�������ڣ�" << yyyy << "/" << mm << "/" << dd << endl;
}
