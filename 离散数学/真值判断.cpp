//判断真值
#include <iostream>
#include <string>
#include <map>

using namespace std;

/*
*说明：
*     用！表示 否定
*     用& 表示 合取
*     用| 表示 析取
*     用- 表示 条件
*     用= 表示 双条件
*/

map<char, int> value_map;
int value = 0;
string expr;

//真值转换函数

void change_val(int &s) {
	if (s == 0) {
		s = 1;
	} else {
		s = 0;
	}
}

//处理连接词

int deal_cal(int par1, char par2, int par3) {
	switch(par2) {
		case '&'://合取
			return par1 && par3;
			break;
		case '|'://析取
			return par1 || par3;
			break;
		case '-'://条件
			return !(par1 == 1 && par3 == 0);
			break;
		case '='://双条件
			return (par1 == par3);
			break;
		default:
			cout<<"有某些命题的真值错误"<<endl;
			break;
	}
}

//没有括号的表达式

int run_unkh_expr(string & str) {
	int a;
	int par_value;//该部分表达式的值
	string::iterator it = str.begin();
	for(; it != str.end(); it++) {
		if(*it == '!') {
			string::const_iterator init_it = it+1;//保存！符后的下一个位置
			change_val(value_map[*(init_it)]);//转换真值

			str.erase(it);//删除否定符号
		}
	}
	it = str.begin();
	par_value = value_map[*it];
	string::size_type l = str.length();
	if(l == 1) {
		return par_value;
	} else {
		for(; it != str.end() - 1;) {
			++it;
			char b = *it;
			par_value = deal_cal(par_value,b,value_map[*(++it)]);
		}
	}
	return par_value;
}

int run_expr(string & Expr) {//扫描括号
	int sum_kh = 0;//括号数
	string::iterator iter;
	string::iterator addr_kh[50];//用于记录括号的位置
	char kind_kh[50];//用于记录括号的类型

	for(iter = Expr.begin(); iter != Expr.end(); iter++) {
		if(*iter == '(' || *iter == ')') {
			addr_kh[sum_kh] = iter;
			kind_kh[sum_kh] = *iter;
			sum_kh++;
		}
	}

	if(0 == sum_kh) { //如果没有括号
		value = run_unkh_expr(Expr);
		return value;
	} else {
		int i = 0;
		for(; i <= sum_kh; i++) {
			if(kind_kh[i] == ')')//找到最内级的括号并跳出循环
				break;
		}
		//取出最内层没有括号的字符串
		string in_str = string(addr_kh[i-1]+1,addr_kh[i]);
		//算出最内层表达式的值
		value = run_unkh_expr(in_str);
		static char var = '1';

		value_map[var] = value;//将括号整体设为一个字符‘1’
		string::iterator ite = addr_kh[i-1];//"字符(的位置"

		//判断（是不是表达式的开头
		string::iterator init_i;
		bool is_begin = false;
		if(ite == expr.begin()) {
			is_begin = true;
		} else {
			init_i = addr_kh[i-1]-1;
		}

		expr.erase(ite,addr_kh[i]+1);//删除掉最内层表达式包括括号在内

		if(is_begin == true) {
			expr = var+expr;
		} else {
			expr.insert(init_i+1,var);
		}
		var = var +1;
		value = run_expr(expr);

		return value;
	}
}

int main() {
	cout << "请先输入合式公式表达式" << endl;
	cout << "用！表示 否定 用& 表示 合取 用| 表示 析取 用- 表示 条件 用= 表示 双条件" << endl; 
	cin >> expr;

	string::const_iterator iter = expr.begin();
	for(; iter != expr.end(); iter++) {
		if(*iter != '!' && *iter != '&' && *iter != '=' && *iter != '-' && *iter!='|' && *iter!='('&&*iter!=')') {
			value_map[*iter] = 1;//为每一个原子命题默认为真
		}
	}

	cout << "请依次再输入各个原子命题的真值选项：" << endl;
	cout << "1 :true" << endl;
	cout << "0 :false" << endl;
	for(map<char,int>::const_iterator it = value_map.begin(); it != value_map.end(); ++it) { //为每个原子命题赋真值
		cout << "请输入" << it->first << "的真值：" << endl;
		int c;
		cin >> c;
		if(c != 1 && c != 0) {
			cout << "您的输入有误。" << endl;
		} else {
			value_map[it->first]=c;
		}

	}
	for(map<char,int>::iterator yy = value_map.begin(); yy != value_map.end(); yy++) {
		cout << "value_map " << yy -> first << yy -> second << endl;
	}

	int val= run_expr(expr);
	cout << "该合式表达式的真值为：" << val << endl;
}
