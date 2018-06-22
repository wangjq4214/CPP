#include <iostream>
#include "teacher.h"

using std::cout;
using std::cin;
using std::endl;

void Teacher::set() {
	People::set();
	cout << "请输入职务：" << endl;
	cin >> principalship; 
	cout << "请输入部门：" << endl;
	cin >> department;
}

void Teacher::display() {
	People::display();
	cout << "职务：" << principalship << endl;
	cout << "部门：" << department << endl;
}
