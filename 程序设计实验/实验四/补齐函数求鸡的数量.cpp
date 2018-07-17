#include <iostream> 
#include <cmath> 

using namespace std; 

void chick(int,int); 

int main() 
{
	int n, m; 
	cin >> n >> m; 
	chick(n, m); 
	return 0; 
} 

void chick(int num,int money)  
{
	for (int i = 0; i < num; i++)
	{
		for (int k = 0; k < num; k++)
		{
			for (int j = 0; j < num; j++)
			{
				if ((i + j + k) == num && (5 * i + 3 * k + j/3.0)== money)
				{
					cout << 'A' << i << ',' << 'B' << k << ',' << 'C' << j << endl;
				}
			}
		}
	}
}
