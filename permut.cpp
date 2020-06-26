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
        int * arr = new int[n];
        for(int i = 0 ; i < n ; i++)
            cin >> arr[i];

        int * brr = new int[n];
        for(int i = 0 ; i < n ; i++)
            cin >> brr[i];

        for(int i = 0 ; i < e ; i++)
        {
            int v1, v2;
            cin >> v1 >> v2;
            edges[v1 - 1].push_back(v2 - 1);
            edges[v2 - 1].push_back(v1 - 1);
        }

        unordered_set<unordered_set<int> * > * ans = getComponents(edges, n);
        unordered_set< unordered_set < int > * > :: iterator it = ans -> begin();
        vector<unordered_set<int>> P;
        vector<unordered_set<int>> Q;
        while(it != ans -> end())
        {
            unordered_set<int> S1;
            unordered_set<int> S2;
            unordered_set<int> * component = *it;
            unordered_set<int>::iterator it1 = component -> begin();
            while(it1 != component -> end())
            {

                S1.insert(arr[*it1]);
                S2.insert(brr[*it1]);
                it1++;
            }
            P.push_back(S1);
            Q.push_back(S2);
            it++;
        }


        int flag = 0;
        n = P.size();
        for(int i = 0 ; i < n ; i++)
        {
            unordered_set<int>:: iterator it;
            for(it = P[i].begin(); it != P[i].end() ; it++)
            {
                unordered_set<int> :: iterator itt;
                itt =  Q[i].find(*it);
                if(itt == Q[i].end())
                {
                    flag = 1;
                    break;
                }
            }
        }
        if(flag)
            cout << "NO"<< endl;
        else
            cout << "YES" << endl;
    }
	return 0;
}
