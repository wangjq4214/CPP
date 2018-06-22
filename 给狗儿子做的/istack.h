#ifndef STACK_H
#define STACK_H

const int maxLen = 100;

template<typename element>
class iStack {
	private:
		int count; // ������
		element data[maxLen]; // ˳�򴢴�ṹ
	public:
		iStack(); // ���캯��
		bool empty(); // �ж��Ƿ�Ϊ��
		bool full(); // �ж�ջ�Ƿ�Ϊ��
		bool get_top(element &x); // ȡջ��Ԫ��
		bool push(element x); // Ԫ����ջ
		bool pop(); // ɾ��ջ��
};

#endif
