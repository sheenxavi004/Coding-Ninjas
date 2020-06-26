#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	if(b == 0)
		return a;

	return gcd(b, a % b);
}

int main()
{
	int n;
	cin >> n;
	long long sum = 0;
	for(int i = 1 ; i <= n ; i++)
	{
		int g = gcd(n, i);
		sum += (n * i) / g;
	}
	cout << sum << endl;
	return 0;
}