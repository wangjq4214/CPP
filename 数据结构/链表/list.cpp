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
/*建立链表
（1、本例程中的表均为单向表 大家可以自行构建循环表、双向表等
2、本例程采用尾部开始构建链表的方式 大家可以尝试使用end指针从头部开始构建）
首先使用point申请一块内存（此时会调用node的构造函数）
然后将point给到head
通过point访问其中的元素（这是个好习惯工程大了会清晰明了）
接着point重新申请一块内存 即前一链节
最后使前一链节的next指针指向下一数据单元*/

void Linkedlist::InsertHead(node n) {
	point = &n;
	point->next = head;
	head = point;
	length++;
}
/*在头部插入元素
首先对传进来的node取地址 并用point指向
然后将head给到point的next指针
然后再使head指向头部
最后链表长度+1*/

void Linkedlist::Insert(node n, int pos) {
	if (pos < 0 || pos > length) {
		cout << "此为无效位置！！" << endl << endl;
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
/*插入节点
首先判断插入的位置是否符合规范 如插入位置 < 0或者插入位置 > length 输出无效
如果插入位置为0 调用InsertHead(node)
如果插入位置 > 0
则定义一个计数体进行计数（注意计数体的初始值为1） 将head赋给point
接下来遍历链表 直到找到对应位置
此时point所指位置为第pos个
接着将n的next指向pos+1
再使得pos个的next指向n
即插入完毕*/

int Linkedlist::Find(node n) {
	point = head;
	int count = 1;
	while (!(n.name == point->name && n.num == point->num)) {
		point = point->next;
		count++;
	}
	if (count > length) {
		cout << "链表中不存在这样的节点！！" << endl << endl;
		return -1;
	} else {
		return count;
	}
}

/*查找节点
首先将head赋给point
定义计数体（注意初始值仍为1）
遍历链表后如果count比length大 则输出不存在 且返回-1
否则返回该节点所在位置*/

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
/*删除节点
首先通过Find(node)查找节点位置 并将位置储存到pos
然后当pos == -1 结束函数
当pos == 1时
新建一个临时容器temp存储head 然后将head指向第二个链节 链表长度-1
当pos等于其他值时
遍历链表定位到要删除节点的前一个
新建一个临时容器temp存储point->next 然后将point->next指向第二个链节 链表长度-1*/

void Linkedlist::Length() {
	cout << "链表的长度为：" << length << endl << endl;
}
//输出链表长度

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
/*链表反序
当链表为空时 结束函数
否则定义curNode指向第一个链节 nextNode指向下一个链节 临时容器temp
未到原链表尾端时循环
temp指向第三个链节
第二个链节的指针域指向第一个链节
一直向后移动直至结束
将原来的第一个链节的指针域设置为NULL
head更新为现在的头*/

void Linkedlist::Print() {
	point = head;
	if (head == NULL) {
		return;
	} else {
		while (point != NULL) {
			cout << "学号：" << point->num << endl;
			cout << "名字：" << point->name << endl << endl;
			point = point->next;
		}
	}
}

/*打印输出
应该大家都能看懂把我就不写注释了
（其实是我不想写了^_^）*/

Linkedlist::~Linkedlist() {
	for(int i = 0; i < length; i++) {
		point = head;
		head = head->next;
		delete point;
	}
}
/*析构函数
主要就是delete么*/
