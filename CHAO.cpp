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
		int arr[n];
		for(int i = 0 ; i < n ; i++)
			cin >> arr[i];

		int maxm = 0, sum = 0;
		for(int i = 0 ; i < n ; )
		{
			int x = arr[i];
			maxm = max(abs(x - 1 - i), maxm);
			sum += abs(x - i - 1);
			i += x - 1;
		}

		if(maxm > 2)
			cout << "Too chaotic" << endl;
		else
			cout << sum << endl;

	}
	return 0;
}