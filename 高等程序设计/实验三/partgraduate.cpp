#include <iostream>
#include "partgraduate.h"

using std::cin;
using std::cout;
using std::endl;

void Partgraduate::set() {
	People::set();
	cout << "�������ţ�" << endl;
	cin >> classNO;
	cout << "������ְ��" << endl;
	cin >> principalship; 
	cout << "�����벿�ţ�" << endl;
	cin >> department;
	cout << "������רҵ��" << endl;
	cin >> subject; 
	cout << "�����뵼ʦ��Ϣ��" << endl;
	adviser.set();
}

void Partgraduate::display() {
	People::display();
	cout << "��ţ�" << classNO << endl;
	cout << "ְ��" << principalship << endl;
	cout << "���ţ�" << department << endl;
	cout << "רҵ��" << subject << endl;
	cout << "��ʦ��Ϣ��" << endl;
	adviser.display(); 
}
