#include <iostream>
#include "people.h"

using std::cout;
using std::cin;
using std::endl;

People::People() {
	number = "NULL";
	name = "NULL";
	sex = 'N';
	id = "NULL";
}

People::People(const People &peo) {
	number  = peo.number;
	name = peo.name;
	sex = peo.sex;
	birthday = peo.birthday;
	id = peo.id;
}

void People::set() {
	cout << "请输入编号：" << endl;
	cin >> number;
	cout << "请输入姓名：" << endl;
	cin >> name;
	cout << "请输入性别（以M、F表示）：" << endl;
	cin >> sex;
	birthday.set();
	cout << "请输入身份证号：" << endl;
	cin >> id;
}

void People::display() {
	cout << "编号：" << number << endl;
	cout << "姓名：" << name << endl;
	cout << "性别：" << sex << endl;
	birthday.display();
	cout << "身份证号：" << id << endl;
}

People::~People() {
	cout << "析构函数被调用" << endl;
}
