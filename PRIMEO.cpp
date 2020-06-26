#include <iostream>
using namespace std;

void seive(int n, bool * primes, int size)
{
	for(int i = n * n ; i <= size ; i += n)
		primes[i] = false;
}
int main()
{
	int n;
	cin >> n;
	bool * primes = new bool[n + 1];
	for(int i = 0 ; i <= n ; i++)
		primes[i] = true;
	primes[0] = false;
	primes[1] = false;
	int count = 0;
	for(int i = 2 ; i * i <= n ; i++)
	{
		if(primes[i])
			seive(i, primes, n);
	}
	for(int i = 0 ; i <= n ; i++)
		if(primes[i])
			count++;
	cout << count << endl;
	return 0;
}