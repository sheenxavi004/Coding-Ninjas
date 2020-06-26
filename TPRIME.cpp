#include <iostream>
using namespace std;

void seive(bool primes[], int n)
{
	for(int i = n * n ; i < 1001 ; i += n)
		primes[i] = false;
}
int main()
{
	int n;
	cin >> n;
	bool primes[1001];
	for(int i = 0 ; i < 1001 ; i++)
		primes[i] = true;
	primes[0] = primes[1] = false;

	for(int i = 2 ; i * i < 1001; i++)
		if(primes[i])
			seive(primes, i);

	int prev = 2;
	for(int i = 3 ; i < 1001; i++)
	{
		if(primes[i])
		{
			if((i - prev) == 2)
			{
				cout << prev << " " << i << endl;
				n--;
			}
			if(n == 0)
				break;
			prev = i;
		}
	}
	return 0;
}