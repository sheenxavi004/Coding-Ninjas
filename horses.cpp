#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

struct coordinate{
    int x, y;
};

int fact(int n)
{
    long * dp = new long[n + 1];
    dp[0] = 1;
    for(int i = 1 ; i <= 1 ; i++)
        dp[i] = ((dp[i] % mod) * (i % mod)) % mod;
    
    int ans = (int)(dp[n] % mod);
    return ans;
		
}
bool checkValid(int X1, int Y1, int X2, int Y2)
{
    if(X1 + 2 == X2 && Y1 + 1 == Y2)
        return true;
    if(X1 + 2 == X2 && Y1 - 1 == Y2)
        return true;
    if(X1 - 2 == X2 && Y1 + 1 == Y2)
        return true;
    if(X1 - 2 == X2 && Y1 - 1 == Y2)
        return true;
    
    if(Y1 + 2 == Y2 && X1 + 1 == X2)
        return true;
    if(Y1 + 2 == Y2 && X1 - 1 == X2)
        return true;
    if(Y1 - 2 == Y2 && X1 + 1 == X2)
        return true;
    if(Y1 - 2 == Y2 && X1 - 1 == X2)
        return true;
    
    return false;
}
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
        int m, n ,q;
        cin >> m >> n >> q;
        vector<int> * edges = new vector<int>[q];
        coordinate arr[q];
		
        for(int i = 0 ; i < q; i++)
            cin >> arr[i].x >> arr[i].y;

        for(int i = 0 ; i < q ; i++)
        {
            for(int j = 0 ; j < q ; j++)
            {
                if(j == i)
                    continue;
                if(checkValid(arr[i].x, arr[i].y, arr[j].x, arr[j].y))
                {
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }
        unordered_set<unordered_set<int> * > * ans = getComponents(edges, q);
        unordered_set< unordered_set < int > * > :: iterator it = ans -> begin();
        long ansF = 1;
        while(it != ans -> end())
        {
            unordered_set<int> * component = *it;
            int mult = component -> size();
            ansF = ((ansF % mod) * (mult % mod)) % mod;
            it++;
        }
        cout << ansF << endl;
    }
	return 0;
}