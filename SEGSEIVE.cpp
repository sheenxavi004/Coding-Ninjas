#include <iostream>
#include <limits.h>
using namespace std;

void seive(int n, bool * primes)
{
	for(int i = n * n ; i < INT_MAX ; i += n)
		primes[i] = false;
}
int main()
{
	bool * primes = new bool[INT_MAX];
	for(int i = 0 ; i < INT_MAX ; i++)
		primes[i] = true;
	primes[0] = false;
	primes[1] = false;
	for(int i = 2 ; i * i < INT_MAX ; i++)
	{
		if(primes[i])
			seive(i, primes);
	}
	int t;
	cin >> t;
	while(t--)
	{
		int l, u;
		cin >> u >> l;
		int count = 0;
		for(int i = l ; i <= u ; i++)
			if(primes[i])
				count++;
		cout << count << endl;
	}
	return 0;
}