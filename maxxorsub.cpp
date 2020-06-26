#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int arr[n];
	for(int i = 0 ; i < n ; i++)
		cin >> arr[i];

	unsigned int max_xor = INT_MIN;

	for(int i = 0 ; i < n ; i++)
	{
		unsigned int curr_xor = ~arr[i];
		for(int j = i; j < n ; j++)
		{
			curr_xor = curr_xor ^ arr[i];
			if(curr_xor > max_xor)
				max_xor = curr_xor;
		}
	}

	cout << max_xor << endl;
}