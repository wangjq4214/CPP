//ตฺศýีย25ฬโ

#include <iostream>

using namespace std;

int main()
{
	char i,j,k;

	for (i = 'X'; i <= 'Z'; i++)

	{
		for (j = 'X'; j <= 'Z'; j++)

		{
			if (i != j)
			{
				for (k = 'X'; k <= 'Z'; k++)
				{
					if (i != k && j != k)
					{
						if (i != 'X' && k != 'X' && k != 'Z')
						{
							cout << "A-" << i << " B-" << j << " C-" << k; 
						}
					}
				}
			}
		}
	}

	return 0;
}
