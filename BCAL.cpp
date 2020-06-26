#include<bits/stdc++.h>
using namespace std;

int main()
{
	int m;
	cin >> m;
	vector<int> ans;
	int n;
	cin >> n;
	while(n--)
	{
		string a;
		cin >> a;
		int carry = 0;
		if(ans.empty())
		{
			for(int i = m - 1 ; i >= 0 ; i--)
			{
				int a_bit = a[i] - 48;
				ans.push_back(a_bit);
			}
		}
		else
		{
			int size = ans.size();
			for(int i = size - 1 ; i >= 0 ; i--)
			{
				int a_bit = 0 ;
				if(i >= size - m)
					a_bit = a[i - (size - m)] - 48;
				int sum = a_bit + ans[size - i - 1] + carry;
				ans[size - i + 1] = sum % 2;
				carry = sum / 2;
			}
			while(carry > 0)
			{
				ans.push_back(carry % 2);
				carry /= 2;
			}
		}
	}
	int size = ans.size();
	for(int i = size - 1; i >= 0 ; i--)
	{
		cout << ans[i];
	}
	return 0;
}