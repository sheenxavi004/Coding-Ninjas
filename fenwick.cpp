#include<bits/stdc++.h>
using namespace std;

void update(int index, int value, int * bit,int n)
{
	for(;index <= n; index += index&(-index))
		bit[index] += value;
}

int query(int index, int * bit)
{
	int sum = 0;
	for(; index > 0 ; index -= index & (-index))
		sum += bit[index];

	return sum;
}
int main()
{
	int n;
	cin >> n;
	int * arr = new int[n + 1]();
	int * bit = new int[n + 1]();
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> arr[i];
		update(i, arr[i], bit, n);
	}

	cout << "Sum of elements from 2 to 6 : " << query(6,bit) - query(2,bit) << endl;

	delete [] arr;
	delete [] bit;
}