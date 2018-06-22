//�ж���ֵ
#include <iostream>
#include <string>
#include <map>

using namespace std;

/*
*˵����
*     �ã���ʾ ��
*     ��& ��ʾ ��ȡ
*     ��| ��ʾ ��ȡ
*     ��- ��ʾ ����
*     ��= ��ʾ ˫����
*/

map<char, int> value_map;
int value = 0;
string expr;

//��ֵת������

void change_val(int &s) {
	if (s == 0) {
		s = 1;
	} else {
		s = 0;
	}
}

//�������Ӵ�

int deal_cal(int par1, char par2, int par3) {
	switch(par2) {
		case '&'://��ȡ
			return par1 && par3;
			break;
		case '|'://��ȡ
			return par1 || par3;
			break;
		case '-'://����
			return !(par1 == 1 && par3 == 0);
			break;
		case '='://˫����
			return (par1 == par3);
			break;
		default:
			cout<<"��ĳЩ�������ֵ����"<<endl;
			break;
	}
}

//û�����ŵı��ʽ

int run_unkh_expr(string & str) {
	int a;
	int par_value;//�ò��ֱ��ʽ��ֵ
	string::iterator it = str.begin();
	for(; it != str.end(); it++) {
		if(*it == '!') {
			string::const_iterator init_it = it+1;//���棡�������һ��λ��
			change_val(value_map[*(init_it)]);//ת����ֵ

			str.erase(it);//ɾ���񶨷���
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

int run_expr(string & Expr) {//ɨ������
	int sum_kh = 0;//������
	string::iterator iter;
	string::iterator addr_kh[50];//���ڼ�¼���ŵ�λ��
	char kind_kh[50];//���ڼ�¼���ŵ�����

	for(iter = Expr.begin(); iter != Expr.end(); iter++) {
		if(*iter == '(' || *iter == ')') {
			addr_kh[sum_kh] = iter;
			kind_kh[sum_kh] = *iter;
			sum_kh++;
		}
	}

	if(0 == sum_kh) { //���û������
		value = run_unkh_expr(Expr);
		return value;
	} else {
		int i = 0;
		for(; i <= sum_kh; i++) {
			if(kind_kh[i] == ')')//�ҵ����ڼ������Ų�����ѭ��
				break;
		}
		//ȡ�����ڲ�û�����ŵ��ַ���
		string in_str = string(addr_kh[i-1]+1,addr_kh[i]);
		//������ڲ���ʽ��ֵ
		value = run_unkh_expr(in_str);
		static char var = '1';

		value_map[var] = value;//������������Ϊһ���ַ���1��
		string::iterator ite = addr_kh[i-1];//"�ַ�(��λ��"

		//�жϣ��ǲ��Ǳ��ʽ�Ŀ�ͷ
		string::iterator init_i;
		bool is_begin = false;
		if(ite == expr.begin()) {
			is_begin = true;
		} else {
			init_i = addr_kh[i-1]-1;
		}

		expr.erase(ite,addr_kh[i]+1);//ɾ�������ڲ���ʽ������������

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
	cout << "���������ʽ��ʽ���ʽ" << endl;
	cout << "�ã���ʾ �� ��& ��ʾ ��ȡ ��| ��ʾ ��ȡ ��- ��ʾ ���� ��= ��ʾ ˫����" << endl; 
	cin >> expr;

	string::const_iterator iter = expr.begin();
	for(; iter != expr.end(); iter++) {
		if(*iter != '!' && *iter != '&' && *iter != '=' && *iter != '-' && *iter!='|' && *iter!='('&&*iter!=')') {
			value_map[*iter] = 1;//Ϊÿһ��ԭ������Ĭ��Ϊ��
		}
	}

	cout << "���������������ԭ���������ֵѡ�" << endl;
	cout << "1 :true" << endl;
	cout << "0 :false" << endl;
	for(map<char,int>::const_iterator it = value_map.begin(); it != value_map.end(); ++it) { //Ϊÿ��ԭ�����⸳��ֵ
		cout << "������" << it->first << "����ֵ��" << endl;
		int c;
		cin >> c;
		if(c != 1 && c != 0) {
			cout << "������������" << endl;
		} else {
			value_map[it->first]=c;
		}

	}
	for(map<char,int>::iterator yy = value_map.begin(); yy != value_map.end(); yy++) {
		cout << "value_map " << yy -> first << yy -> second << endl;
	}

	int val= run_expr(expr);
	cout << "�ú�ʽ���ʽ����ֵΪ��" << val << endl;
}
