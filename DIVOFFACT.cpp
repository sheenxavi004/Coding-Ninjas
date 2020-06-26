#include <iostream>
#include <math.h>
using namespace std;

#define mod 1000000007

void makeSeive(bool seive[], int k, int size)
{
	for(int i = k * k ; i <= size ; i += k)
		seive[i] = false;
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		bool seive[n + 1];
		for(int i = 0 ; i <= n ; i++)
			seive[i] = true;

		seive[0] = false;
		seive[1] = false;

		for(int i = 2; i * i <= n ; i++)
		{
			if(seive[i])
				makeSeive(seive, i, n);
		}

		long factors = 1;
		for(int i = 0 ; i <= n ; i++)
		{
			if(seive[i])
			{
				int k = n;
				int smallAns = 1;
				for(int j = 1 ; pow(i,j) <= n ; j++)
					smallAns += n / (pow(i, j));

				factors = ((factors % mod) * (smallAns % mod)) % mod;

			}
		}
		cout << factors << endl;
	}
	return 0;
}