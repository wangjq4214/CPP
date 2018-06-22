#include <iostream>
#include "list.h"

using namespace std;

int main() {
	Linkedlist list(5);
	string a[5] = {"2017******01", "2017******02", "2017******03", "2017******04", "2017******05"};
	string b[5] = {"张三", "李四", "王五", "赵六", "孙七"};
	node n;
	n.num = "2017******06";
	n.name = "周八";
	
	list.establish(a, b);//建立 
	list.Print();//打印 
	list.InsertHead(n);//头部插入
	list.Length();//长度 
	list.Print();//打印 
	list.Remove(n);//删除 
	list.Length();//长度 
	list.Insert(n, 7);//插入 
	list.Insert(n, -1);//插入 
	list.Insert(n, 3);//插入
	cout << "n的位置为：" << list.Find(n) << endl << endl;
	list.Print(); 
	list.Length();//长度
	list.Reverse();//反序 
	list.Print();//打印
	list.Remove(n);
	list.Print();
}
