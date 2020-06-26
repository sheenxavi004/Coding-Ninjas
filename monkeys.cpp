#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> *edges, int st, bool visited[], unordered_set<int> * component)
{
    visited[st] = true;
    component -> insert(st);
    int n = edges[st].size();
    for(int i = 0 ; i < n ; i++)
    {
        int next = edges[st][i];
        if(!visited[next])
            dfs(edges, next, visited, component);
    }
}

unordered_set<unordered_set<int> * > * getComponents(vector<int> *edges, int V)
{
    bool *visited = new bool[V];
    for(int i = 0 ; i < V ; i++)
        visited[i] = false;

    unordered_set<unordered_set<int> * > * ans = new unordered_set<unordered_set<int> * >();
    for(int i = 0 ; i  <  V ; i++)
        if(!visited[i])
        {
            unordered_set<int> * component = new unordered_set<int>();
            dfs(edges, i, visited, component);
            ans -> insert(component);
        }
    delete [] visited;
    return ans;
}

int main()
{
	//code
    int t;
    cin >> t;
    while(t--)
    {
        int n, e;
        cin >> n >> e;
        vector<int> * edges = new vector<int>[n];
        for(int i = 0 ; i < e ; i++)
        {
            int v1, v2;
            cin >> v1 >> v2;
            edges[v1 - 1].push_back(v2 - 1);
            edges[v2 - 1].push_back(v1 - 1);
        }

        long long * arr = new long long[n];
        for(int i = 0 ; i < n ; i++)
            cin >> arr[i];

        long long final_ans = 0;
        unordered_set<unordered_set<int> * > * ans = getComponents(edges, n);
        unordered_set< unordered_set < int > * > :: iterator it = ans -> begin();
        vector<unordered_set<int>> P;
        vector<unordered_set<int>> Q;
        while(it != ans -> end())
        {
            unordered_set<int> * component = *it;
            unordered_set<int>::iterator it1 = component -> begin();
            long long curr_ans = 0;
            while(it1 != component -> end())
            {
                curr_ans += arr[*it1];
                it1++;
            }
            if(curr_ans > final_ans)
                final_ans = curr_ans;
            it++;
        }

        cout << final_ans << endl;
    }
	return 0;
}
