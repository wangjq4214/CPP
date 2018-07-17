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
/*�ڵ㶨�� ѧ��+����
���������� num name
ָ���� *next
�Լ��ṹ��Ĺ��캯�� node()���г�ʼ��
һ��Ҫ��next��ʼ��ΪNULL*/

class Linkedlist {
	private:
		node *head;
		node *point;
		int length;
		/*������ĳ��ö��巽����
		���峤�� �Լ�ͷָ��head ָ��ָ��point*/
	public:
		Linkedlist(int a = 0) {
			head = NULL;
			point = NULL;
			length = a;
		}
		/*���캯��һ�㽫head��point��end��ʼ��ΪNULL
		������Ĭ�ϳ�ʼ��Ϊ0*/
		void establish(string*, string*);//�������� �������˴�Ҳ����õ���ָ���������ķ�ʽ 
		void InsertHead(node);//��ͷ������ڵ�
		void Insert(node, int);//������λ�ò���ڵ�
		int Find(node);//���ҽڵ�
		void Remove(node);//ɾ���ڵ�
		void Length();//����������
		void Reverse();//������
		void Print();//��ӡ����
		~Linkedlist();//��������
};

#endif
