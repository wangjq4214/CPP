#include <iostream>
#include "teacher.h"

using std::cout;
using std::cin;
using std::endl;

void Teacher::set() {
	People::set();
	cout << "������ְ��" << endl;
	cin >> principalship; 
	cout << "�����벿�ţ�" << endl;
	cin >> department;
}

void Teacher::display() {
	People::display();
	cout << "ְ��" << principalship << endl;
	cout << "���ţ�" << department << endl;
}
