//3.2

#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
	double bj, g;

	cout << "����������뾶��ߣ�" << endl;
	cin >> bj;
	cin >> g;
	cout << "Բ�ܳ���" << setiosflags(ios::fixed) << setprecision(2) << 2 * bj * M_PI << endl;
	cout << "Բ�����" << setiosflags(ios::fixed) << setprecision(2) << bj * bj * M_PI << endl;
	cout << "Բ��������" << setiosflags(ios::fixed) << setprecision(2) << 4 * M_PI * bj * bj << endl;
	cout << "Բ�������" << setiosflags(ios::fixed) << setprecision(2) << 4/3 * M_PI * bj * bj *bj <<endl;
	cout << "Բ�������" << setiosflags(ios::fixed) << setprecision(2) << g * bj * bj * M_PI << endl;
	
	return 0; 
}
