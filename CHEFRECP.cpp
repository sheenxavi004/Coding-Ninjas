#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int visited[1001];
		memset(visited, -1, sizeof(int) * 1001);
		int n;
		cin >> n;
		int * arr = new int[n];
		for(int i = 0 ; i < n ; i++)
			cin >> arr[i];

		int flag = 1;
		unordered_set<int> counts;
		for(int i = 0 ; i < n ; i++)
		{
			//If not present
			if(visited[arr[i]] == -1)
				visited[arr[i]] = 1;
			else
			{
				if(arr[i - 1] == arr[i])
					visited[arr[i]]++;
				else
				{
					flag = 0;
					break;
				}
			}
		}
		for(int i = 1 ; i < 1001 ; i++)
		{
			if(visited[i] == -1)
				continue;
			auto it = counts.find(visited[i]);
			if(it == counts.end())
				counts.insert(visited[i]);
			else
			{
				flag = 0;
				break;
			}

		}
		if(flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

		delete [] arr;
	}
	return 0;
}