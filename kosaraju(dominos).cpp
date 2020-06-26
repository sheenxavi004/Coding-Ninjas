#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> * edges, int start,unordered_set<int> &visited,stack<int> &finishedVisited)
{
	visited.insert(start);
	int n = edges[start].size();
	for(int i = 0 ; i < n ; i++)
		if(visited.count(edges[start][i]) == 0)
			dfs(edges, i, visited, finishedVisited);
	finishedVisited.push(start);
}
void dfs2(vector<int> * edges, int start, unordered_set<int> &visited)
{
	visited.insert(start);
	int n = edges[start].size();
	for(int i = 0 ; i < n ; i++)
		if(visited.count(edges[start][i]) == 0)
			dfs2(edges, i, visited);

}

int ans(vector<int> * edges, vector<int> * edgesT, int V)
{
	unordered_set<int> visited;
	stack<int> finishedVisited;

	for(int i = 0 ; i < V ; i++)
	{
		if(visited.count(i) == 0)
			dfs(edges, i, visited, finishedVisited);
	}

	visited.clear();
	int ans = 0;
	while(finishedVisited.size() != 0)
	{

		int element = finishedVisited.top();
		finishedVisited.pop();
		if(visited.count(element) == 0)
		{
			dfs2(edgesT, element, visited);
			ans++;
		}
	}

	return ans;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int V, E;
		cin >> V >> E;

		vector<int> * edges = new vector<int>[V];
		vector<int> * edgesT = new vector<int>[V];
		for(int i = 0 ; i < E ; i++)
		{
			int L, R;
			cin >> L >> R;
			edges[L - 1].push_back(R - 1);
			edgesT[R - 1].push_back(L - 1);
		}
		cout << ans(edges, edgesT, V) << endl;
	}
	return 0;
}
