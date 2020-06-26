#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int count = 0;
		while(n > 4)
		{
			count += n / 5;
			n /= 5;
		}
		cout << count << endl;
	}
	return 0;
}