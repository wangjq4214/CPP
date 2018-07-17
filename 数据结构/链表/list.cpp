#include <iostream>
#include "list.h"

using namespace std;

void Linkedlist::establish(string *a, string *b) {
	point = new node;
	for (int i = length - 1; i >= 0; i--) {
		head = point;
		point->num = a[i];
		point->name = b[i];
		point = new node;
		point->next = head;
	}
}
/*��������
��1���������еı��Ϊ����� ��ҿ������й���ѭ����˫����
2�������̲���β����ʼ��������ķ�ʽ ��ҿ��Գ���ʹ��endָ���ͷ����ʼ������
����ʹ��point����һ���ڴ棨��ʱ�����node�Ĺ��캯����
Ȼ��point����head
ͨ��point�������е�Ԫ�أ����Ǹ���ϰ�߹��̴��˻��������ˣ�
����point��������һ���ڴ� ��ǰһ����
���ʹǰһ���ڵ�nextָ��ָ����һ���ݵ�Ԫ*/

void Linkedlist::InsertHead(node n) {
	point = &n;
	point->next = head;
	head = point;
	length++;
}
/*��ͷ������Ԫ��
���ȶԴ�������nodeȡ��ַ ����pointָ��
Ȼ��head����point��nextָ��
Ȼ����ʹheadָ��ͷ��
���������+1*/

void Linkedlist::Insert(node n, int pos) {
	if (pos < 0 || pos > length) {
		cout << "��Ϊ��Чλ�ã���" << endl << endl;
	} else if (pos == 0) {
		InsertHead(n);
	} else {
		int count = 1;
		point = head;
		while (count < pos) {
			point = point->next;
			count++;
		}
		n.next = point->next;
		point->next = &n;
		length++;
	}
}
/*����ڵ�
�����жϲ����λ���Ƿ���Ϲ淶 �����λ�� < 0���߲���λ�� > length �����Ч
�������λ��Ϊ0 ����InsertHead(node)
�������λ�� > 0
����һ����������м�����ע�������ĳ�ʼֵΪ1�� ��head����point
�������������� ֱ���ҵ���Ӧλ��
��ʱpoint��ָλ��Ϊ��pos��
���Ž�n��nextָ��pos+1
��ʹ��pos����nextָ��n
���������*/

int Linkedlist::Find(node n) {
	point = head;
	int count = 1;
	while (!(n.name == point->name && n.num == point->num)) {
		point = point->next;
		count++;
	}
	if (count > length) {
		cout << "�����в����������Ľڵ㣡��" << endl << endl;
		return -1;
	} else {
		return count;
	}
}

/*���ҽڵ�
���Ƚ�head����point
��������壨ע���ʼֵ��Ϊ1��
������������count��length�� ����������� �ҷ���-1
���򷵻ظýڵ�����λ��*/

void Linkedlist::Remove(node n) {
	int pos = Find(n);
	if (pos == -1) {
		return;
	} else if (pos == 1) {
		node *temp = head;
		head = temp->next;
		length--;
	} else {
		point = head;
		int count = 1;
		while (count < pos) {
			point = point->next;
			count++;
		}
		node *temp = point->next;
		point->next = temp->next;
		length--;
	}
}
/*ɾ���ڵ�
����ͨ��Find(node)���ҽڵ�λ�� ����λ�ô��浽pos
Ȼ��pos == -1 ��������
��pos == 1ʱ
�½�һ����ʱ����temp�洢head Ȼ��headָ��ڶ������� ������-1
��pos��������ֵʱ
��������λ��Ҫɾ���ڵ��ǰһ��
�½�һ����ʱ����temp�洢point->next Ȼ��point->nextָ��ڶ������� ������-1*/

void Linkedlist::Length() {
	cout << "����ĳ���Ϊ��" << length << endl << endl;
}
//���������

void Linkedlist::Reverse() {
	if (head == NULL)
		return;
	node *curNode = head, *nextNode = head->next, *temp;
	while (nextNode != NULL) {
		temp = nextNode->next;
		nextNode->next = curNode;
		curNode = nextNode;
		nextNode = temp;
	}
	head->next = NULL;
	head = curNode;
}
/*������
������Ϊ��ʱ ��������
������curNodeָ���һ������ nextNodeָ����һ������ ��ʱ����temp
δ��ԭ����β��ʱѭ��
tempָ�����������
�ڶ������ڵ�ָ����ָ���һ������
һֱ����ƶ�ֱ������
��ԭ���ĵ�һ�����ڵ�ָ��������ΪNULL
head����Ϊ���ڵ�ͷ*/

void Linkedlist::Print() {
	point = head;
	if (head == NULL) {
		return;
	} else {
		while (point != NULL) {
			cout << "ѧ�ţ�" << point->num << endl;
			cout << "���֣�" << point->name << endl << endl;
			point = point->next;
		}
	}
}

/*��ӡ���
Ӧ�ô�Ҷ��ܿ������ҾͲ�дע����
����ʵ���Ҳ���д��^_^��*/

Linkedlist::~Linkedlist() {
	for(int i = 0; i < length; i++) {
		point = head;
		head = head->next;
		delete point;
	}
}
/*��������
��Ҫ����deleteô*/
