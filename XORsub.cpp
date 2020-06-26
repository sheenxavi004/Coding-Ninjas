#include<bits/stdc++.h>
using namespace std;

struct trieNode{
	trieNode *left;
	trieNode *right;
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
			curr = curr -> left;
		}
		else
		{
			if(!curr -> right)
				curr -> right = new trieNode;
			curr = curr -> right;
		}
	}
}
int findMaxXorPair(trieNode * head, int * arr, int n)
{
	int max_xor = INT_MIN;
	int trav_xor = arr[0];
	insert(arr[0], head);
	for(int i = 1 ; i < n ; i++)
	{
		trieNode * curr = head;
		int curr_xor = 0;
		trav_xor = trav_xor ^ arr[i];
		for(int j = 31 ; j >= 0 ; j--)
		{
			int b = (trav_xor >> j) & 1;

			if(b == 0)
			{
				if(curr -> right)
				{
					curr_xor += pow(2,j);
					curr = curr -> right;
				}
				else
				{
					curr = curr -> left;
				}
			}
			else
			{
				if(curr -> left)
				{					
					curr_xor += pow(2,j);
					curr = curr -> left;
				}
				else
				{
					curr = curr -> right;
				}
			}
		}
		trieNode * icurr = head;
		insert(trav_xor, icurr);
		max_xor = max(max(curr_xor, trav_xor), max_xor);
	}
	return max_xor;
}
int main()
{
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0 ; i < n ; i++)
		cin >> arr[i];

	trieNode * head = new trieNode;
	cout << findMaxXorPair(head, arr, n) << endl;
	return 0;
}