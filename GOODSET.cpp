#include <iostream>
#include <algorithm>
using namespace std;

#define mod 1000000007
#define MAXSIZE 750001

void seive(long sarr[], int x)
{
	int additive = sarr[x];
	for(int i = x * 2 ; i < MAXSIZE ; i += x)
		sarr[i] = (sarr[i] % mod + additive % mod) % mod;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int arr[n];
		for(int i = 0 ; i < n ; i++)
			cin >> arr[i];

		sort(arr, arr + n);
		long num = 0;
		long sarr[MAXSIZE];
		for(int i = 0 ; i < MAXSIZE ; i++)
			sarr[i] = 1;
 
		for(int i = 0 ; i < n ; i++)
		{
			seive(sarr, arr[i]);
		}

		for(int i = 0 ; i < n ; i++)
			num = (num % mod + sarr[arr[i]] % mod) % mod;

		cout << num << endl;
	}
	return 0;
}