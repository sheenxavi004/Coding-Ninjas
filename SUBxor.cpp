#include<bits/stdc++.h>
using namespace std;

class trieNode{
	public : 
	trieNode *left;
	trieNode *right;
	int lcount;
	int rcount;

	trieNode()
	{
		right = left = NULL;
		lcount = rcount = 0;
	}
};

void insert(int n, trieNode * head)
{
	trieNode * curr = head;
	for(int i = 31 ; i >= 0; i--)
	{
		//Checking the bit at current pos, here b stores the bit
		int b = (n >> i) & 1;
		
		if(b == 0)
		{
			if(!curr -> left){
				curr -> left = new trieNode;
			}
			curr -> lcount++;
			curr = curr -> left;
		}
		else
		{
			if(!curr -> right){
				curr -> right = new trieNode;
			}
			curr -> rcount++;
			curr = curr -> right;
		}
	}
}
int lesserXORs(trieNode * head, int * arr, int n, int k)
{
	int trav_xor = 0;
	int count = 0;
	insert(0, head);
	for(int i = 0 ; i < n ; i++)
	{
		trieNode * curr = head;
		trav_xor = trav_xor ^ arr[i];
		for(int j = 31 ; j >= 0 ; j--)
		{
			int b = (trav_xor >> j) & 1;
			int p = (k >> j) & 1;
			
			if(curr)
			{
				if(p == 1)
				{
					if(b == 1)
					{
						if(curr -> right)
						{
							count += curr -> rcount;
						}
						curr = curr -> left;
					}
					else
					{
						if(curr -> left)
						{
							count += curr -> lcount;
						}
						curr = curr -> right;
					}
				}
				else
				{
					if(b == 1)
					{
						curr = curr -> right;
					}
					else
					{
						curr = curr -> left;
					}
				}
			}
			else
				break;

		}
		trieNode * icurr = head;
		insert(trav_xor, icurr);
	}
	return count;
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, k;
		cin >> n >> k;
		int arr[n];
		for(int i = 0 ; i < n ; i++)
			cin >> arr[i];

		trieNode * head = new trieNode;
		cout << lesserXORs(head, arr, n, k) << endl;
	}
	return 0;
}