//输入2个十进制整数，分别按照十六进制，十进制，八进制表格式输出。

#include <iostream>
#include <iomanip> 

using namespace std;

int main()
{
	int a, b;
	cout.setf(std::ios::left);
	cout.setf(ios_base::showbase);
	
	cin >> a >> b;
	cout << setw(8) << hex << a << setw(8) << dec << a << setw(8) << oct << a << endl;
	cout << setw(8) << hex << b << setw(8) << dec << b << setw(8) << oct << b << endl;
	
	return 0;
}
