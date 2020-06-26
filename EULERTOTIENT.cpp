#include <iostream>
using namespace std;

void seivef(int n, int * seive, int size)
{
	for(int i = n * 2 ; i <= size ; i += n)
		seive[i] = (seive[i] * (n - 1)) / n;
}
int main()
{
	int n;
	cin >> n;
	int * seive = new int[n + 1];
	for(int i = 0 ; i <= n ; i++)
		seive[i] = i;

	for(int i = 2 ; i <= n ; i++)
	{
		if(seive[i] == i)
		{
			seive[i]--;
			seivef(i, seive, n);
		}
	}
	cout << seive[n] << endl;
	return 0;
}
