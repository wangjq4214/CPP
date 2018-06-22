// ջ
#include <iostream>

using namespace std;

class sqStack {
	private:
		enum {
		    maxSize = 100
		};
		int data[maxSize];
		int top;
	public:
		sqStack();
		~sqStack();
		bool isEmpty();
		void pushInt(int x);
		int popInt();
		int getTop();
		void display();
};

sqStack::sqStack() {
	top = -1;
}

sqStack::~sqStack() {}

bool sqStack::isEmpty() {
	return top == -1;
}

void sqStack::pushInt(int x) {
	if (top == maxSize - 1) {
		cout << "���" << endl;
	} else {
		++top;
		data[top] = x;
	}
}

int sqStack::popInt() {
	int tmp = 0;
	if (top == -1) {
		cout << "ջ�ѿ�" << endl;
	} else {
		tmp = data[top--];
	}
	return tmp;
}

int sqStack::getTop() {
	int tmp = 0;
	if(top == -1) {
		cout << "ջ�գ�" << endl;
	} else {
		tmp = data[top];
	}
	return tmp;
}

void sqStack::display() {
	cout << "ջ��Ԫ�أ�" << endl;
	for (int index = top; index >= 0; --index) {
		cout << data[index] << endl;
	}
}

int main() {
	sqStack st;
	cout << "ջ�գ�" << st.isEmpty() << endl;
	for (int i = 1; i < 10; i++) {
		st.pushInt(i);
	}
	st.display();
	cout << "��һ��ջ" << endl;
	st.popInt();
	cout << "ջ��Ԫ��:" << st.getTop() << endl;
	st.popInt();
	st.display();
	
	return 0;
}
