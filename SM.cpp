#include<bits/stdc++.h>
using namespace std;

int solver(int x, int y, int z, int ***dp, string a, string b, string c)
{
	if(z == 0)
		return 1;

	if(x + y < z)
		return 0;

	if(dp[x][y][z] != -1)
		return dp[x][y][z];

	int ways = 0;
	for(int i = x - 1; i >= 0 ; i--)
	{
		if(a[i] == c[z - 1])
			ways += solver(i, y, z - 1, dp, a, b, c);
	}

	for(int j = y - 1; j >= 0 ; j--)
	{
		if(b[j] == c[z - 1])
			ways += solver(x, j, z - 1, dp, a, b, c);
	}

	dp[x][y][z] = ways;
	return ways;
}
int main()
{
	string a, b, c;
	cin >> a >> b >> c;
	int x = a.length(), y = b.length(), z = c.length();
	int *** dp = new int ** [x + 1];
	for(int i = 0 ; i <= x ; i++)
	{
		dp[i] = new int * [y + 1];
		for(int j = 0 ; j <= y ; j++)
			dp[i][j] = new int[z + 1];
	}
	for(int i = 0 ; i <= x ; i++)
		for(int j = 0 ; j <= y ; j++)
			for(int k = 0 ; k <= z ; k++)
				dp[i][j][k] = -1;
	cout << solver(x, y, z, dp, a, b, c) << endl;
	for(int i = 0 ; i <= x ; i++)
	{
		for(int j = 0 ; j <= y ; j++)
		{
			delete []dp[i][j];
		}
		delete []dp[i];
	}
	delete []dp;
	return 0;
}