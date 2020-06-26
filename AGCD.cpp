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
	int t;
	cin >> t;
	while(t--)
	{
		int a;
		cin >> a;
		string b;
		cin >> b;

		int modb = 0;
		int size = b.length();
		for(int i = 0 ; i < size ; i++)
		{
			modb = ((modb * 10) % a + (b[i] - 48)) % a;
		}
		cout << gcd(a, modb) << endl;
	}
	return 0;
}