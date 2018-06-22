// ตฺศýีย13ฬโ

#include <iostream>

using namespace std;

int main()
{
	int i;
	cin >> i;
	
	switch (i / 100000)
	{
			case 0 :
		{
			cout << i * 0.1;
			break;
		}
	case 1:
		{
			cout << 10000 + (i - 100000) * 0.075;
			break;
		}
	case 2:
	case 3:
		{
			cout << 17500 + (i - 200000) * 0.05;
			break;
		}
	case 4:
	case 5:
		{
			cout << 27500 + (i - 400000) * 0.03; 
			break;
		}
	case 6:
	case 7:
	case 8:
	case 9:
		{
			cout << 33500 + (i - 600000) * 0.015; 
			break;
		}
	default:
		{
			cout << 39500 + (i - 600000) * 0.01;
			break;
		}
	}

	return 0;
} 
