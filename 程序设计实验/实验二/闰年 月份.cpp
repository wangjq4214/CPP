//ÈòÄê ÔÂ·İ.cpp 

#include<iostream>

using namespace std;

int main()
{
	int a, b;
	
	cin >> a >> b;
	
	switch (b)
	{
		case 1 :
		case 3 :
		case 5 :
		case 7 :
		case 8 :
		case 10 :
		case 12 :
			cout << "31";
			break;
		case 4 :
		case 6 :
		case 9 :
		case 11 :
			cout << "30";
			break;
		case 2 :
			if ((a % 4 == 0 && a % 100 != 0)||a % 400 == 0)
			{
				cout << "29";
			}
			else
			{
				cout << "28";
			}
			break;
	}
	
	return 0;
}
