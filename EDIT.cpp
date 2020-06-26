#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    string ans="YES";
	    unordered_map<int,int> umap; 
	    int ele,pre;
	    cin>>ele;
	    umap[ele]=1;
	    pre=ele;
	    for(int i=1;i<n;i++)
	    {
            cin>>ele;
	         if (umap.find(ele)!= umap.end())
	         {
	         		if(pre!=ele)
	         		{
	             		ans="NO";
	             		break;
	             	}
	             	else
	             	{
	                     umap[ele]++;
	             	}
	         }
	         else
	                 umap[ele]=1;
	         pre=ele;
	    }
	   vector<int>values;
	   for (auto x : umap) 
            values.push_back(x.second); 
        sort(values.begin(),values.end());
        for(int i=1;i<values.size();i++)
        {
            if(values[i]==values[i-1])
            {
                ans="NO";
                break;
            }
        }
        cout<<ans<<endl;
        // cout<<"*****"<<endl;
	}
	return 0;
}