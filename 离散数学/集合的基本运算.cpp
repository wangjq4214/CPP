//重写代码
//使用string及其中的函数简化对字符串的处理
//使用iomanip格式化输出
//将重复功能写为函数缩短代码量 
#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;
string A,B;
string aa,bb;//aa为并集，bb为交集；
void output(string a) {
	int i;
	for(i=0; i<a.length()-1; i++)
		cout<<a[i]<<",";
	cout<<a[i]<<endl;
}
void chuli(string &a) { //1 直接在输入的字符串上进行删除重复部分
	for(int i=0; i<a.length(); i++) {
		if((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z')||(a[i]>='0'&&a[i]<='9')) {
			for(int j=0; j<i; j++) {
				if(a[i]==a[j]) {
					a.replace(i,1,"");
					i--;
					break;
				}
			}
		} else {
			a.replace(i,1,"");
			i--;
		}
	}
}
void bing(string a,string b) { //2 使用字符串可直接“拼接 ” 调用已有函数处理
	aa=a+b;
	chuli(aa);
	cout<<"集合并集：";
	output(aa);
}
void jiao(string a,string b) {
	for(int i=0; i<a.length(); i++) {
		int j;
		for(j=0; j<b.length(); j++)
			if(a[i]==b[j]) break;
		if(j<b.length()) bb+=a[i];
	}
	cout<<"集合交集：";
	if(bb.length()==0) cout<<endl;
	else
		output(bb);
}
void cha(string a,string b) { //3 整合为一个函数处理集合的差和对称差
	string cc;
	cc=a;
	for(int i=0; i<b.length(); i++) {
		cc.replace(cc.find(b[i]),1,"");
	}
	if(cc.length()==0) cout<<endl;
	else
		output(cc);
}

void zhiji(string a,string b) {
	cout<<"直积：";
	if(a.length()!=0&&b.length()!=0) {
		int i;
		for(i=0; i<a.length()-1; i++) {
			for(int j=0; j<b.length(); j++) {
				cout<<"<"<<a[i]<<","<<b[j]<<">,";
			}
		}
		int jj;
		for(jj=0; jj<b.length()-1; jj++) {
			cout<<"<"<<a[i]<<","<<b[jj]<<">,";
		}
		cout<<"<"<<a[i]<<","<<b[jj]<<">";
	} else cout<<endl;
}
int main() {
	cin>>A>>B;
	chuli(A);
	cout<<"A：";
	output(A);
	chuli(B);
	cout<<"B：";
	output(B);
	bing(A,B);
	jiao(A,B);
	cout<<"集合的差：";
	cha(A,bb);
	cout<<"集合的对称差：";
	cha(aa,bb);
	zhiji(A,B);
	return 0;
}
