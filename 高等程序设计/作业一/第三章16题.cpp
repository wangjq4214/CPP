// ตฺศýีย16ฬโ

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
	int js1 = 0, js2 = 0, js3 = 0, js4 = 0;
	string str;
	getline(cin, str);
	
	for (int i = 0; i < str.length(); i++)
	{
		if (isalpha(str[i]))
		{
			js1++;
		}
		else if (isblank(str[i]))
		{
			js2++;
		}
		else if (isdigit(str[i]))
		{
			js3++;
		}
		else
		{
			js4++;
		}
	}
	
	cout << js1 << endl << js2 << endl << js3 << endl << js4;
	
	return 0;
}
