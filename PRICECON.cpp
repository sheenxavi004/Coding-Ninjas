#include<iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, k;
		cin >> n >> k;
		int ans = 0;
		for(int i = 0 ; i < n ; i++)
		{
			int x;
			cin >> x;
			if(x > k)
				ans += x - k;
		}

		cout << ans << endl;
	}
	return 0;
}