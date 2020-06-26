#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> factors;
	for(int i = 2 ; i <= n ; i++)
	{
		int count = 0;
		while(n % i == 0)
		{
			count++;
			n /= i;
		}
		if(count > 0)
			factors.push_back(make_pair(i, count));

	}

	for(auto it = factors.begin(); it != factors.end() ; it++)
	{
		for(int i = 0 ; i < (it -> second) ; i++)
		{
			if((i == ((it -> second) - 1)) && ((it + 1) == factors.end()))
				cout << it -> first << endl;
			else
				cout << it -> first << " x ";
		}
	}
	return 0;
}