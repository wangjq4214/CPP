//×Ö·û.cpp

#include <iostream>
#include <cctype>

using namespace std;

int main()
{
	char ch;
	
	cin >> ch;
	if (islower(ch))
	{
		cout << "lower case";
	}
	if (isupper(ch))
	{
		cout << "upper case";
	}
	if (isdigit(ch))
	{
		cout << "number case";
	} 
	if (!(islower(ch)||isupper(ch)||isdigit(ch))) 
	{
		cout << "other case";
	}
	
	return 0;
 } 
