#include <bits/stdc++.h>
using namespace std;

bool bipartite(vector<int> * edges, int n, unordered_set<int> visited)
{
	if(n == 0)
		return true;
	unordered_set<int> sets[2];
	vector<int> pending;
	sets[0].insert(0);
	pending.push_back(0);
	visited.erase(0);
	while(pending.size() > 0)
	{
		int current = pending.back();
		pending.pop_back();
		int currentSet = sets[0].count(current) > 0 ? 0 : 1;
		for(int i = 0 ; i < edges[current].size(); i++)
		{
			int neighbour = edges[current][i];
			if(sets[0].count(neighbour) == 0 && sets[1].count(neighbour)==0)
			{
				sets[1 - currentSet].insert(neighbour);
				pending.push_back(neighbour);
				visited.erase(neighbour);
			}
			else if(sets[currentSet].count(neighbour) > 0)
				return false;
		}
	}
	return true;
}

int main()
{
	while(true)
	{
		int n;
		cin >> n;
		if(n == 0)
			break;

		vector<int> * edges = new vector<int>[n];
		int m;
		cin >> m;
		unordered_set<int> visited;
		for(int i = 0 ; i < m ; i++)
		{
			int j, k;
			cin >> j >> k;
			edges[j].push_back(k);
			edges[k].push_back(j);
			visited.insert(j);
			visited.insert(k);

		}
		bool ans;
		while(visited.size() == 0)
		{
			ans = bipartite(edges, n, visited);
			if(ans == false)
				break;
		}
		if(ans){
			cout << "yes" << endl;
		}
		else
			cout << "no" << endl;
	}
}