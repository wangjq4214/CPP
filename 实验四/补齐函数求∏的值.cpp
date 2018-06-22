#include <iostream> 
#include <cmath> 
#include <iomanip> 

using namespace std; 

float f(float); 

int main()
{ 
	float e=0.0; 
	cin>>e; 
    cout << setiosflags(ios::fixed)<<setprecision(5)<<f(e); 
    return 0; 
} 

float f(float t)
{
	float re = 0.0;
	float i = 1.0, k;
	do
	{
		re = re + (1.0 / i);
		if (i > 0)
		{
			i += 2;
		}
		else
		{
			i -= 2;
		}
		i = -i;
		k = fabs(1 / i); 
	}while (k >= t);
	re = re + (1.0 / i);
	
	return re * 4;
}
