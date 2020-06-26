#include<bits/stdc++.h>
using namespace std;
#define mod 100001
int main()
{
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	map<int, int> freq;
	int ans = n + 1;
	int dp[1001][1001];
	memset(dp, 0, sizeof(int) * 1001 * 1001);
	for(int j = n - 2 ; j >= 0 ; j--)
	{
		for(int i = j + 1 ; i < n ; i++)
		{
			int diff = abs(arr[j] - arr[i]);
			dp[diff][j] = 1 + dp[diff][i];
			ans += dp[diff][j];
		}
	}

	cout << ans << endl;
	return 0;
}