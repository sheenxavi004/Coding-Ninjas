#include<bits/stdc++.h>
using namespace std;

void buildtree(int *arr, int *tree, int start, int end, int treeNode)
{
	int mid = (start + end)/2;
	if(start == end)
	{
		tree[treeNode] = arr[start];
		return;
	}

	buildtree(arr, tree, start, mid, treeNode * 2);
	buildtree(arr, tree, mid + 1, end, treeNode * 2 + 1);
	tree[treeNode] = tree[2 * treeNode] + tree[2 * treeNode + 1];	
}

void updateLazy
int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *tree = new int[18];

	buildtree(arr, tree, 0, 8, 1);

	for(int  i = 1 ; i < 18 ; i++)
		cout << tree[i] << endl;
	return 0;
}