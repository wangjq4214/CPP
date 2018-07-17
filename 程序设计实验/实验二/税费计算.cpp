//À∞∑—º∆À„.cpp

#include <iostream>
#include <iomanip>

using namespace std; 

int main()
{
	int sr;
	double sf; 
	
	cin >> sr;
	
	if (sr <= 800)
	{
		sf = 0;
	}
	if (sr > 800 && sr <= 1200)
	{
		sf = (sr - 800) * 0.05;
	}
	if (sr > 1200 && sr <= 2000)
	{
		sf = (sr - 1200) * 0.08 + 20;
	}
	if (sr > 2000)
	{
		sf = (sr - 2000) * 0.2 + 84;
	}
	
	cout << setiosflags(ios::fixed) << setprecision(2) << sf;
	
	return 0;
}
