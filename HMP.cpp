#include<bits/stdc++.h>
using namespace std;

class trieNode{
	public :
		trieNode ** children;

	trieNode(){
		children = new trieNode*[27];
		for(int i = 0 ; i < 27 ; i++)
			children[i] = NULL;
	}
};

void insert(string str, trieNode * head)
{
	int size = str.length();
	trieNode * curr = head;
	for(int i = 0 ; i < size ; i++)
	{
		if(str[i] == '.')
		{
			if(!curr -> children[26])
			{
				curr -> children[26] = new trieNode;
			}
			curr = curr -> children[26];
			continue;
		}

		int ch = str[i] - 97;
		if(!curr -> children[ch])
		{
			curr -> children[ch] = new trieNode;
		}
		curr = curr -> children[ch];
	}
}

void dfs(vector<string> &ans, trieNode * head, string str)
{
	trieNode * curr = head;
	if(curr -> children[26])
	{
		ans.push_back(str);
	}
	for(int i = 0 ; i < 26 ; i++)
	{
		if(curr -> children[i])
		{
			char ch = 'a' + i;
			dfs(ans, curr -> children[i], str + ch);
		}
	}
	return;
}

vector<string> query(string str, trieNode * head)
{
	trieNode * curr = head;
	int flag = 0;
	int size = str.size();

	vector<string> ans;
	for(int i = 0 ; i < size ; i++)
	{
		int ch = str[i] - 97;
		if(!curr -> children[ch])
		{
			flag = 1;
			break;
		}
		curr = curr -> children[ch];
	}
	if(flag)
	{
		ans.push_back("No suggestions");
		insert(str + ".", head);
		return ans;
	}

 	dfs(ans, curr, str);
	return ans;

}
int main()
{
	int n, q;
	cin >> n;

	trieNode * head = new trieNode;
	while(n--)
	{
		string str;
		cin >> str;
		insert(str + ".", head);
	}

	cin >> q;
	while(q--)
	{
		string str;
		cin >> str;

		vector<string> ans = query(str, head);
		int size = ans.size();
		for(int i = 0 ; i < size ; i++)
			cout << ans[i] << endl;
	}
}