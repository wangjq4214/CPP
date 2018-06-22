// Լɪ��
#include <iostream>

using namespace std;

struct Node {   // �����ڵ�
	int num;
	Node *next;
};

Node** create(int);  // ��������
Node** del(Node**, int);  //ɾ���ڵ�

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
	} // ��ɽ�������

	tail->num = m;
	tail->next = head; // ���ѭ������

	list[0] = head;
	list[1] = tail;

	return list; // ���ض���ָ���¼ͷβ
}

Node** del(Node **list, int m) {
	Node *head = list[0];
	Node *tail = list[1];

	if (head->num == m) { // ����дhead->num == m�����
		Node *temp;
		temp = head;

		head = head->next;
		tail->next = head; // ֱ�ӽ����ջ� ͨ����¼βָ�뽵����һ�����Ӷ� ��������Ӱ�첻��

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
