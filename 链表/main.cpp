#include <iostream>
#include "list.h"

using namespace std;

int main() {
	Linkedlist list(5);
	string a[5] = {"2017******01", "2017******02", "2017******03", "2017******04", "2017******05"};
	string b[5] = {"����", "����", "����", "����", "����"};
	node n;
	n.num = "2017******06";
	n.name = "�ܰ�";
	
	list.establish(a, b);//���� 
	list.Print();//��ӡ 
	list.InsertHead(n);//ͷ������
	list.Length();//���� 
	list.Print();//��ӡ 
	list.Remove(n);//ɾ�� 
	list.Length();//���� 
	list.Insert(n, 7);//���� 
	list.Insert(n, -1);//���� 
	list.Insert(n, 3);//����
	cout << "n��λ��Ϊ��" << list.Find(n) << endl << endl;
	list.Print(); 
	list.Length();//����
	list.Reverse();//���� 
	list.Print();//��ӡ
	list.Remove(n);
	list.Print();
}
