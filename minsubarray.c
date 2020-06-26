#include<bits/stdc++.h>
using namespace std;

void buildTree(int arr[], int tree[], int start, int end, int treeNode)
{
    if(start == end)
    {
        tree[treeNode] = arr[start];
        return;
    }
    
    int mid = (first + last) / 2;
    
    buildTree(arr, tree, start, mid, treeNode * 2);
    bulldTree(arr, tree, mid + 1, end, treeNode * 2 + 1);
    
    tree[treeNode] = tree[treeNode * 2] + tree[treeNode * 2 + 1];
}

void updateTree(int arr[], int tree[], int start, int end, int treeNode, int pos, int value)
{
    if(start == end)
    {
        tree[treeNode] = value;
        arr[start] = value;
        return;
    }
    
    int mid = (start + end) / 2;
    if(mid < pos)
        updateTree(arr, tree, mid + 1, end, treeNode * 2 + 1, pos, value);
    else
        updateTree(arr, tree, start, mid, treeNode * 2, pos, value);
    tree[treeNode] = tree[treeNode * 2] + tree[treeNode * 2 + 1];
}

int queryTree(int arr[], int tree[], int start, int end, int treeNode, int left, int right)
{
	if(start < left || right > end)
        return INT_MAX;
    
    if(start >= left && right >= end)
    {
        int mid = (start + end) / 2;
        int ans1 = queryTree(arr, tree, start, mid, treeNode * 2, left, right);
        int ans2 = queryTree(arr, tree, mid + 1, end, treeNode * 2 + 1, left, right);
        return min(ans1, ans2);
    }
	int mid = (start + end) / 2;
    int ans1 = queryTree(arr, tree, start, mid, treeNode * 2, left, right);
    int ans2 = queryTree(arr, tree, mid + 1, end, treeNode * 2 + 1, left, right);
    return min(ans1, ans2);
}
int main() {

	// Write your code here
    int n, t;
    cin >> n >> t;
    int arr[n];
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i];
    
    int tree[4 * n];
    
    buildTree(arr, tree, 0, n - 1, 1);
    while(t--)
    
}