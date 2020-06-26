#include <iostream>
using namespace std;

#define MAX 1000001

void seive(int * fact , int n)
{
	for(int i = n ; i < MAX ; i += n)
		fact[i]++;
}
int main()
{
	int t;
	cin >> t;

	int * fact = new int[MAX];
	for(int i = 0 ; i < MAX ; i++)
		fact[i] = 0;

	for(int i = 2 ; i < MAX ; i++)
	{
		if(!fact[i])
			seive(fact, i);
	}
	while(t--)
	{
		int a, b, n;
		cin >> a >> b >> n;
		int count = 0;
		for(int i = a; i <= b ; i++)
			if(fact[i] == n)
				count++;
			
		cout << count << endl;
	}
	return 0;
}