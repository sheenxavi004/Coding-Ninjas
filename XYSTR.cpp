#include<iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string str;
		cin >> str;

		int pairs = 0;
		int n = str.size();
		for(int i = 0 ; i < n - 1;)
		{
			if(str[i] == 'x')
			{
				if(str[i + 1] == 'y')
				{
					pairs++;
					i += 2;
				}
				else
					i++;
	
			}
			else
			{
				if(str[i + 1] == 'x')
				{
					pairs++;
					i += 2;
				}
				else
					i++;
			}
		}

		cout << pairs << endl;
	}
	return 0;
}