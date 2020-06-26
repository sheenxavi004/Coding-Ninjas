#include<bits/stdc++.h>
using namespace std;

class trieNode{
	public :
		trieNode ** children;
		int weight;

	trieNode(){
		children = new trieNode*[26];
		for(int i = 0 ; i < 26 ; i++)
			children[i] = NULL;

		weight = 0;
	}
};

void insert(string str, int weight, trieNode * head)
{
	int size = str.length();
	trieNode * curr = head;
	for(int i = 0 ; i < size ; i++)
	{
		int ch = str[i] - 97;
		if(curr -> children[ch])
		{
			if(weight > curr -> children[ch] -> weight)
				curr -> children[ch] -> weight = weight;
		}
		else
		{
			curr -> children[ch] = new trieNode;
			curr -> children[ch] -> weight = weight;
		}
		curr = curr -> children[ch];
	}
}

int query(string str, trieNode * head)
{
	trieNode * curr = head;
	int flag = 0;
	int size = str.size();

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
		return -1;
	return curr -> weight;
}
int main()
{
	int n, q;
	cin >> n >> q;

	trieNode * head = new trieNode;
	while(n--)
	{
		string str;
		int weight;
		cin >> str >> weight;
		insert(str, weight, head);
	}

	while(q--)
	{
		string str;
		cin >> str;
		cout << query(str, head) << endl;
	}
}