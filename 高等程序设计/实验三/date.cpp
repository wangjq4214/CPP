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
	cout << "请输入出生日期（以空格区分）：" << endl; 
	cin >> yyyy >> mm >> dd;
}

void Date::display() {
	cout << "出生日期：" << yyyy << "/" << mm << "/" << dd << endl;
}
