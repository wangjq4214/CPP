// Í¼ÏñÐý×ª

#include <iostream>

using namespace std;

int main()
{
	int row, col;
	cin >> row >> col;
	int cs[row][col], sc[col][row];
	
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> cs[i][j];
			sc[col - (j + 1)][i] =cs[i][j];
		}
	}
	
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			cout << sc[i][j] << " ";
		}
		
		cout << endl;
	}
	
	return 0;
} 
