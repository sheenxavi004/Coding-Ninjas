#include<bits/stdc++.h>
using namespace std;

bool compare(event A, event B)
{
	return A.second < B.second;
}

void update(int index, int * bit, int n)
{
	for(; index <= n ; index += index & (-index))
		bit[index]++;
}

int query(int index, int * bit, int n)
{
	int count = 0;
	for(;index >= 0 ; index -= index & (-index))
		count += bit[index];
	return count;
}
int main()
{
	int n;
	cin >> n;

	int * arr = new int[n + 1];
	for(int i = 1 ; i <= n ; i++ )
		cin >> arr[i];
	sort(arr, arr + n);
	int q;
	cin >> q;
	while(q--)
	{
		int l, r, k;
		cin >> l >> r >> k;
	}

	return 0;
}