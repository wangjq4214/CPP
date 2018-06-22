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
	cout << "�������ţ�" << endl;
	cin >> number;
	cout << "������������" << endl;
	cin >> name;
	cout << "�������Ա���M��F��ʾ����" << endl;
	cin >> sex;
	birthday.set();
	cout << "���������֤�ţ�" << endl;
	cin >> id;
}

void People::display() {
	cout << "��ţ�" << number << endl;
	cout << "������" << name << endl;
	cout << "�Ա�" << sex << endl;
	birthday.display();
	cout << "���֤�ţ�" << id << endl;
}

People::~People() {
	cout << "��������������" << endl;
}
