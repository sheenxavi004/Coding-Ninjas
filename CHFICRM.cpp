#include<iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int fchange = 0, tchange = 0;
		int flag = 1;

		int arr[n];
		for(int i = 0 ; i < n ; i++)
			cin >> arr[i];
		for(int i = 0 ; i < n ; i++)
		{
			int x = arr[i];

			if(x == 5)
			{
				fchange++;
			}
			else if(x == 10)
			{
				if(fchange > 0)
				{
					fchange--;
					tchange++;
				}
				else
				{
					flag = 0;
					break;
				}
			}
			else if(x == 15)
			{
				if(tchange > 0 && tchange > fchange/2)
				{
					tchange--;
				}
				else if(fchange > 1)
				{
					fchange -= 2;
				}
				else
				{
					flag = 0;
					break;
				}
			}
		}
		if(flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}