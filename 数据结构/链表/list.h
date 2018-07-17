#ifndef LIST_H
#define LIST_H

#include <string>

using std::string;

struct node {
	string num;
	string name;
	node *next;
	node() {
		next = NULL;
	}
};
/*节点定义 学号+名字
包含数据域 num name
指针域 *next
以及结构体的构造函数 node()进行初始化
一定要将next初始化为NULL*/

class Linkedlist {
	private:
		node *head;
		node *point;
		int length;
		/*链表类的常用定义方法：
		定义长度 以及头指针head 指向指针point*/
	public:
		Linkedlist(int a = 0) {
			head = NULL;
			point = NULL;
			length = a;
		}
		/*构造函数一般将head、point、end初始化为NULL
		将长度默认初始化为0*/
		void establish(string*, string*);//建立链表 这里用了大家不常用的用指针访问数组的方式 
		void InsertHead(node);//在头部插入节点
		void Insert(node, int);//在任意位置插入节点
		int Find(node);//查找节点
		void Remove(node);//删除节点
		void Length();//返回链表长度
		void Reverse();//链表反序
		void Print();//打印链表
		~Linkedlist();//析构函数
};

#endif
