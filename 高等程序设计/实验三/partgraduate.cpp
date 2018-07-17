#include <iostream>
#include "partgraduate.h"

using std::cin;
using std::cout;
using std::endl;

void Partgraduate::set() {
	People::set();
	cout << "请输入班号：" << endl;
	cin >> classNO;
	cout << "请输入职务：" << endl;
	cin >> principalship; 
	cout << "请输入部门：" << endl;
	cin >> department;
	cout << "请输入专业：" << endl;
	cin >> subject; 
	cout << "请输入导师信息：" << endl;
	adviser.set();
}

void Partgraduate::display() {
	People::display();
	cout << "班号：" << classNO << endl;
	cout << "职务：" << principalship << endl;
	cout << "部门：" << department << endl;
	cout << "专业：" << subject << endl;
	cout << "导师信息：" << endl;
	adviser.display(); 
}
