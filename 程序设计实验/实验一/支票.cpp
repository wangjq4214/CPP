//����֧Ʊ���루����������֧Ʊ����������������ʽҪ�������֧Ʊ����ռ8λ������8λ���򲹳�ǰ������0����֧Ʊ����ԣ���ʼ����������λС�� ��

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int zpdm;
	double zpje;
	
	cin >> zpdm >> zpje;
	
	cout << setfill('0') << setw(8) << zpdm << endl;
	cout << setiosflags(ios::fixed) << setprecision(2) << zpje << endl;
	
	return 0;
}
