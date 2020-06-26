#include<bits/stdc++.h>
using namespace std;

int minCost(int cost[4][4], int n, int j, int mask)
{
	if(j == n)
		return 0;

	int smallAns = INT_MAX;
	for(int i = 0 ; i < n ; i++)
	{
		if(!(mask & (1 << i)))
		{
			smallAns = min(smallAns, cost[j][i] + minCost(cost, n, j + 1, mask | (1 << i)));
		}
	}
	return smallAns;
}
int minCostI(int cost[4][4], int n)
{
	int * dp = new int[1 << n];
	for(int i = 0 ; i < 1 << n ; i++)
		dp[i] = INT_MAX;

	dp[0] = 0;

	for(int mask = 0 ; mask < ((1 << n) - 1) ; mask++)
	{
		int temp = mask;
		//Count number of set bits
		int k = 0;
		while(temp > 0)
		{
			if(temp % 2 == 1)
				k++;

			temp /= 2;
		}

		for(int j = 0 ; j < n ; j++)
		{
			if(!(mask & (1 << j)))
				dp[mask | (1 << j)] = min(dp[mask | (1 << j)], cost[k][j] + dp[mask]);
		}
	}
	int ans = dp[(1 << n) - 1];
	delete [] dp;
	return ans;
}
int main()
{
	int cost[4][4] = {{10, 2, 6, 5}, {1, 15, 12, 8}, {7, 8, 9, 3}, {15, 13, 4, 10}};
	cout << minCost(cost, 4, 0, 0) << endl;
	cout << minCostI(cost, 4);
	return 0;
}