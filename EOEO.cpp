#include<iostream>
using namespace std;

int main()
{
	long long t;
	cin >> t;
	while(t--)
	{
		long long ts;
		cin >> ts;
		long long count = 0;
		if((ts & 1))
			count = ts/2;
		else
		{
			while((ts & 1) == 0)
				ts /= 2;
			count = ts/2;
		}
		cout << count << endl;
	}
	return 0;
}