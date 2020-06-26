#include<bits/stdc++.h>
using namespace std;

int main()
{
	int m, n;
	cin >> m >> n;

	int **graph = new int * [m];
	for(int i = 0 ; i < m ; i++)
		graph[i] = new int[n];

	for(int i = 0 ; i < m ; i++)
		for(int j = 0 ; j < n ; j++)
			cin >> graph[i][j]

	int **dp = new int * [m];
	for(int i = 0 ; i < m ; i++)
		dp[i] = new int[n]();

	for(int i = m - 2 ; i >= 0 ; i--)
		dp[i][n - 1] = graph[i + 1][n - 1] - graph[i][n - 1];

	for(int i = n - 2 ; i >= 0 ; i--)
		dp[m - 1][i] = graph[m - 1][i + 1] - dp[m - 1][i + 1];

	int maxEnergy = INT_MIN;

	for(int i = m - 2; i >= 0 ; i--)
		for(int j = n - 2 ; j >= 0 ; j--)
		{
			dp[i][j] = min(abs(dp[i][j + 1] - dp, dp[i + 1][j]);
			if(maxEnergy < dp[i][j])

		}
	return 0;
}