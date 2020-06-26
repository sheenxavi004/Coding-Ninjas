#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int * lpd = new int[n + 1];

	for(int i = 0 ; i <= n ; i++)
		lpd[i] = i;

	for(int i = 2 ; i * i <= n ; i++)
	{
		if(lpd[i] == i)
		{
			int curr = i;
			for(int j = curr * curr ; j <= n ; j += curr)
			{
				if(lpd[j] == j)
					lpd[j] = i;
			}
		}
	}	
	vector<int> temp;
	bool * isMarked = new bool[n + 1];
	for(int i = 0 ; i <= n ; i++)
		isMarked[i] = false;

	for(int i = n ; i > 0 ; i--)
	{
		if(isMarked[i])
			continue;
		temp.clear();
		isMarked[i] = true;
		temp.push_back(i);
		int lpdi = lpd[i];
		int x = i;
		while(x != 1)
		{
			int y = i - lpdi;
			while(y > 1)
			{
				if(!isMarked[y])
				{
					isMarked[y] = true;
					temp.push_back(y);
				}
				y -= lpdi;
			}
			while(x % lpdi == 0)
				x /= lpdi;
			lpdi = lpd[x];
		}
		int size = temp.size();
		sort(temp.begin(), temp.end());
		for(int i = size - 1 ; i >= 0 ; i--)
			cout << temp[i] << " ";
	}
	delete [] isMarked;
	delete [] lpd;
	return 0;
}