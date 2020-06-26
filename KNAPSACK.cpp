#include<bits/stdc++.h>
using namespace std;


int knapsack(int weights[], int values[], int n, int maxWeight)
{
	int dp[2][maxWeight + 1];
	for(int i = 0 ; i <= maxWeight ; i++)
		dp[0][i] = 0;

	int flag = 1;

	for(int i = 1 ; i <= n ; i++)
	{
		dp[flag][0] = 0;
		for(int j = 1 ; j <= maxWeight ; j++)
		{
			dp[flag][j] = dp[flag ^ 1][j];
			if(j >= weights[i - 1])
				dp[flag][j] = max(dp[flag][j], dp[flag ^ 1][j - weights[i - 1]] + values[i - 1]);

		}
		flag = flag ^ 1;
	}

	return dp[flag ^ 1][maxWeight];
}
int main()
{
	int n;
	cin >> n;
	int weights[n], values[n];

	for(int i = 0 ; i < n ; i++)
		cin >> weights[i];
	for(int i = 0 ; i < n ; i++)
		cin >> values[i];

	int maxWeight;
	cin >> maxWeight;

	cout << knapsack(weights, values, n, maxWeight);

	return 0;
}