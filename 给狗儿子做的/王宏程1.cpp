// 约瑟夫环
#include <iostream>

using namespace std;

struct Node {   // 建立节点
	int num;
	Node *next;
};

Node** create(int);  // 创建链表
Node** del(Node**, int);  //删除节点

int main() {
	int m, s, n;
	cin >> m >> s >> n;
	Node **list = create(m);

	int sum = 0;
	Node *point;
	point = list[1];
	
	while (list[0] != list[1]) {
		if (point->next->num != s) {
			point = point->next;
		} else {
			break;
		}
	}

	while (list[0] != list[1]) {
		while (sum != n - 1) {
			point = point->next;
			sum++;
		}
		
		cout << point->next->num << " "; 
		list = del(list, point->next->num);
		sum = 0;
	}
	
	cout << list[0]->num;
	delete list[0];
	delete list;
	
	return 0;
}

Node** create(int m) {
	Node **list = new Node*[2];

	Node *head, *tail;
	head = tail = new Node;

	for (int i = 1; i < m; i++) {
		tail->num = i;
		tail->next = new Node;
		tail = tail->next;
	} // 完成建立部分

	tail->num = m;
	tail->next = head; // 完成循环部分

	list[0] = head;
	list[1] = tail;

	return list; // 返回二重指针记录头尾
}

Node** del(Node **list, int m) {
	Node *head = list[0];
	Node *tail = list[1];

	if (head->num == m) { // 单独写head->num == m的情况
		Node *temp;
		temp = head;

		head = head->next;
		tail->next = head; // 直接建立闭环 通过记录尾指针降低这一步复杂度 但对整体影响不大

		delete temp;
	}  else {
		Node *temp, *point;

		point = head;
		while (point->next->num != m) {
			point = point->next;
		}

		temp = point->next;
		if (temp == tail) {
			tail = point;
		}
		point->next = temp->next;

		delete temp;
	}

	list[0] = head;
	list[1] = tail;

	return list;
}
