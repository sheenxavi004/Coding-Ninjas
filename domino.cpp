//Bottom elements in Graphs using Kosaraju's Algorithm

#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> * edges, int start,bool visited[],stack<int> &finishedVisited)
{
	visited[start] = true;
	int n = edges[start].size();
	for(int i = 0 ; i < n ; i++)
		if(!visited[edges[start][i]])
			dfs(edges, edges[start][i], visited, finishedVisited);
	finishedVisited.push(start);
}
void dfs2(vector<int> * edges, int start, bool visited[])
{
	visited[start] = true;
	int n = edges[start].size();
	for(int i = 0 ; i < n ; i++)
		if(!visited[edges[start][i]])
			dfs2(edges, edges[start][i], visited);

}

int dominos(vector<int> * edges, int V)
{
	bool visited[V];
	memset(visited, false, sizeof(bool) * V);
	stack<int> finishedVisited;
	for(int i = 0 ; i < V ; i++)
	{
		if(!visited[i])
			dfs(edges, i, visited, finishedVisited);
	}
	memset(visited, false, sizeof(bool) * V);
	int ans = 0;
	while(finishedVisited.size() != 0)
	{
		int element = finishedVisited.top();
		finishedVisited.pop();
		if(!visited[element])
		{
			dfs2(edges, element, visited);
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
		for(int i = 0 ; i < E ; i++)
		{
			int L, R;
			cin >> L >> R;
			edges[L - 1].push_back(R - 1);
		}

		cout << dominos(edges, V) << endl;
	}
	return 0;
}
