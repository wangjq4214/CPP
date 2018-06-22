#include "istack.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <sstream>

using namespace std;

bool isNumber(char); // 扫描数字 
int priority(char); // 判断运算符 
double calculate(string); // 运算

int main() {
	string exp;
	while(1){
		system("cls");
		cout << "请输入表达式(输入0退出程序)：" << endl;
		cin >> exp;
		if (exp == "0") {
			break;
		} else {
			calculate(exp);
		}
	}
}

bool isNumber(char x) {
	if ((x >= '0' && x <= '9') || x == '.') {
		return true;
	} else {
		return false;
	}
}

int priority(char x) {
	if (x == '+' || x == '-') {
		return 0;
	} else if (x == '*' || x == '/') {
		return 1;
	} else if (x == '^') {
		return 2;
	} else if (x == '(' || x == ')') {
		return 3;
	}
}

double calculate(string s) {
	iStack<double> number;
	iStack<char> operate;
	char top;
	int a, b;
	
	for (string::iterator iter = s.begin(); iter != s.end(); iter++) {
		if (isNumber(*iter)) {
			double Temp = 0;
			string temp;
			stringstream sin;
			
			temp += *iter;
			while (isNumber(*(++iter))) {
				temp += *iter;
			}
			
			sin >> temp;
			sin << Temp; 
			
			number.push(Temp);
			temp.clear();
		}
		if (!isNumber(*iter)) {
			if (operate.empty()) {
				operate.push(*iter);
			} else {
				operate.get_top(top);
				
			}
		}
	} 
}
