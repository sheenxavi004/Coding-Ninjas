#include <bits/stdc++.h>
using namespace std;

struct name{
	string first;
	string last;
};

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		name arr[n];
		for(int i = 0 ; i < n ; i++)
		{
			cin >> arr[i].first >> arr[i].last;
		}
		map<string, int> freq;
		for(int i = 0 ; i < n ; i++)
			freq[arr[i].first]++;

		for(int i = 0 ; i < n ; i++)
		{
			if(freq[arr[i].first] > 1)
				cout << arr[i].first << " " << arr[i].last << endl;
			else
				cout << arr[i].first << endl;
		}
	}
	return 0;
}