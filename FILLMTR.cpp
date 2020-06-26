#include<bits/stdc++.h>
using namespace std;

struct edges{
    int v1, v2, weight;
};

bool getParent(int V, int parent[])
{
    if(V == parent[V])
        return V;
    return getParent(parent[V], parent);
}
bool bipartite(vector<int> * edges, int n, int start)
{
    if(n == 0)
        return true;
    unordered_set<int> sets[2];
    vector<int> pending;
    sets[0].insert(start);
    pending.push_back(start);
    while(pending.size() > 0)
    {
        int current = pending.back();
        pending.pop_back();
        int currentSet = sets[0].count(current) > 0 ? 0 : 1;
        int size = edges[current].size();
        for(int i = 0 ; i < size; i++)
        {
            int neighbour = edges[current][i];
            if(sets[0].count(neighbour) == 0 && sets[1].count(neighbour)==0)
            {
                sets[1 - currentSet].insert(neighbour);
                pending.push_back(neighbour);
            }
            else if(sets[currentSet].count(neighbour) > 0)
                return false;
        }
    }
    return true;
}
bool solveFillMtr(edges * arr, int n, int q)
{
  	int * parent = new int[n];
    for(int i = 0 ; i < n ; i++)
        parent[i] = i;

    int i = 0;
    while(i < q)
    {
        int pv1 = getParent(arr[i].v1, parent);
        int pv2 = getParent(arr[i].v2, parent);
    
        if(pv1 != pv2 && arr[i].weight == 0)
			parent[pv2] = pv1;           
        
        i++;
    }
    
    int start;
    vector<int> * edge = new vector<int>[n];
    for(int i = 0; i < q; i++)
    {
        if(arr[i].weight == 1)
        {
            int v1 = getParent(arr[i].v1, parent);
            int v2 = getParent(arr[i].v2, parent);
            edge[v1].push_back(v2);
            edge[v2].push_back(v1);
            start = v1;
        }
    }

    if(bipartite(edge, n, start))
        return true; 

    return false;
}
int main()
{
	//code
    int t;
    cin >> t;
    while(t--)
    {
        int n, q;
        cin >> n >> q;
	
        edges * arr = new edges[q];
        for(int i = 0 ; i < q ; i++)
        {
            int v1, v2, weight; 
            cin >> v1 >> v2 >> weight;
            
            arr[i].v1 = v1 - 1;
            arr[i].v2 = v2 - 1;
            arr[i].weight = weight;
        }
	
        
        if(solveFillMtr(arr, n, q))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
	return 0;
}
