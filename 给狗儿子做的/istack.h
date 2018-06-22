#ifndef STACK_H
#define STACK_H

const int maxLen = 100;

template<typename element>
class iStack {
	private:
		int count; // 计数器
		element data[maxLen]; // 顺序储存结构
	public:
		iStack(); // 构造函数
		bool empty(); // 判断是否为空
		bool full(); // 判断栈是否为满
		bool get_top(element &x); // 取栈顶元素
		bool push(element x); // 元素入栈
		bool pop(); // 删除栈顶
};

#endif
