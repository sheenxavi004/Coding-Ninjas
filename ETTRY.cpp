#include <iostream>
#include <utility>
#include <vector>
#include <math.h>
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

	int value = 1;
	for(auto it = factors.begin(); it != factors.end() ; it++)
	{
		int curr = it -> first, power = it -> second;
		value = value * pow(curr, power - 1) * (curr - 1);
	}
	cout << value << endl;
	return 0;
}