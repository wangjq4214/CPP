//��д����
//ʹ��string�����еĺ����򻯶��ַ����Ĵ���
//ʹ��iomanip��ʽ�����
//���ظ�����дΪ�������̴����� 
#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;
string A,B;
string aa,bb;//aaΪ������bbΪ������
void output(string a) {
	int i;
	for(i=0; i<a.length()-1; i++)
		cout<<a[i]<<",";
	cout<<a[i]<<endl;
}
void chuli(string &a) { //1 ֱ����������ַ����Ͻ���ɾ���ظ�����
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
void bing(string a,string b) { //2 ʹ���ַ�����ֱ�ӡ�ƴ�� �� �������к�������
	aa=a+b;
	chuli(aa);
	cout<<"���ϲ�����";
	output(aa);
}
void jiao(string a,string b) {
	for(int i=0; i<a.length(); i++) {
		int j;
		for(j=0; j<b.length(); j++)
			if(a[i]==b[j]) break;
		if(j<b.length()) bb+=a[i];
	}
	cout<<"���Ͻ�����";
	if(bb.length()==0) cout<<endl;
	else
		output(bb);
}
void cha(string a,string b) { //3 ����Ϊһ�����������ϵĲ�ͶԳƲ�
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
	cout<<"ֱ����";
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
	cout<<"A��";
	output(A);
	chuli(B);
	cout<<"B��";
	output(B);
	bing(A,B);
	jiao(A,B);
	cout<<"���ϵĲ";
	cha(A,bb);
	cout<<"���ϵĶԳƲ";
	cha(aa,bb);
	zhiji(A,B);
	return 0;
}
