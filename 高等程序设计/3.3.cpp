//3.3
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double huashi, c;
	
	cout << "������һ�������¶ȣ�" << endl;
	cin >> huashi;
	c = (5.0/9.0) * (huashi - 32);
	cout << "�����¶ȣ�"  << setiosflags(ios::fixed) << setprecision(2) << c;
	
	return 0; 
}
