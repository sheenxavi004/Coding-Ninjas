//Bottom elements in Graphs using Kosaraju's Algorithm

#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> * edges, int start,unordered_set<int> &visited,stack<int> &finishedVisited)
{
	visited.insert(start);
	int n = edges[start].size();
	for(int i = 0 ; i < n ; i++)
		if(visited.count(edges[start][i]) == 0)
			dfs(edges, edges[start][i], visited, finishedVisited);
	finishedVisited.push(start);
}
void dfs2(vector<int> * edges, int start, unordered_set<int> &visited, unordered_set<int> * component)
{
	visited.insert(start);
	component -> insert(start);
	int n = edges[start].size();
	for(int i = 0 ; i < n ; i++)
		if(visited.count(edges[start][i]) == 0)
			dfs2(edges, edges[start][i], visited, component);

}

unordered_set<unordered_set<int> * > * kosaraju(vector<int> * edges, vector<int> * edgesT, int V)
{
	unordered_set<int> visited;
	stack<int> finishedVisited;
	for(int i = 0 ; i < V ; i++)
	{
		if(visited.count(i) == 0)
			dfs(edges, i, visited, finishedVisited);
	}

	visited.clear();
	unordered_set<unordered_set<int>*>* ans = new unordered_set<unordered_set<int> * >();
	while(finishedVisited.size() != 0)
	{
		unordered_set<int> * component = new unordered_set<int>();
		int element = finishedVisited.top();
		finishedVisited.pop();
		if(visited.count(element) == 0)
		{
			dfs2(edgesT, element, visited, component);
			ans -> insert(component);
		}
	}

	return ans;
}

int main()
{
	int V;
	cin >> V;
	while(V)
	{
		int E;
		cin >> E;

		vector<int> * edges = new vector<int>[V];
		vector<int> * edgesT = new vector<int>[V];
		for(int i = 0 ; i < E ; i++)
		{
			int L, R;
			cin >> L >> R;
			edges[L - 1].push_back(R - 1);
			edgesT[R - 1].push_back(L - 1);
		}
		unordered_set<unordered_set<int> * > * components = kosaraju(edges, edgesT, V);
		vector<int> bottoms;
		auto it = components -> begin();
		while(it != components -> end())
		{
			unordered_set<int> * component = *it;
			auto it2 = component -> begin();
			int flag = 1;
			while(it2 != component -> end())
			{
				int element = *it2;
				int n = edges[element].size();
				for(int i = 0 ; i < n ; i++)
					if(component -> find(edges[element][i]) == component -> end())
					{
						flag = 0;
						break;
					}
				it2++;
			}

			it2 = component -> begin();
			if(flag)
			{
				while(it2 != component -> end())
				{
					int element = *it2;
					bottoms.push_back(element);
					it2++;
				}
			}
			it++;
		}

		sort(bottoms.begin(), bottoms.end());

		int n = bottoms.size();
		for(int i = 0 ; i < n ; i++)
			cout << bottoms[i] + 1 << " ";

		cout << endl;
		cin >> V;
	}
	return 0;
}
