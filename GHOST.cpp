#include<bits/stdc++.h>
using namespace std;

long long ghost(int n, long long mask, long long dp[])
{
    
	if(mask == ((1 << (n + 1)) - 1))
	{
		return 1;
	}
	if(dp[mask] != -1)
		return dp[mask];

	long long ways = 0;
	for(int i = 1 ; i <= n ; i++)
	{
		if(!(mask & (1 << i)))
		{
			bool flag = true;
			for(int j = 1 ; j <= n ; j++)
			{
				if(mask & (1 << j) && (i & j) == i)
				{
					flag = false;
					break;
				}
			}
			if(flag)
			{
				ways += ghost(n, mask | (1 << i), dp);
			}

		}
	}
	dp[mask] = ways;
	return ways;
}
int main()
{
	int n;
	cin >> n;
	long long * dp = new long long[1 << (n + 1)];
	for(int mask = 0 ; mask < (1 << (n + 1)) ; mask++)
		dp[mask] = -1;
	cout << ghost(n, 1, dp) << endl;
	delete [] dp;
	return 0;
}