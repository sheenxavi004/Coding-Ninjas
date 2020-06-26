#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> ans;
	ans.push_back(1);
	for(int i = 2 ; i <= n ; i++)
	{
		int mult = i;
		int size = ans.size();
		int carry = 0;
		for(int j = 0 ; j < size ; j++)
		{
			int product = ans[j] * mult + carry;
			ans[j] = product % 10;
			carry = product / 10;
		}

		while(carry > 0)
		{
			ans.push_back(carry % 10);
			carry /= 10;
		}
	}

	int size = ans.size();
	for(int i = size - 1 ; i >= 0 ; i--)
		 cout << ans[i];
	return 0;
}