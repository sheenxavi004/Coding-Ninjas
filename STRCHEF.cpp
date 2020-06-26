#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string str;
		cin >> str;
		int freq[26];
		memset(freq, 0, sizeof(int) * 26);
		int len = str.length();
		for(int i = 0 ; i < len ; i++)
			freq[str[i] - 97]++;
		int min = INT_MAX;
		int flag = 1;
		int strength = 0;
		for(int i = 0; i < 26 ; i++)
		{
			if(freq[i] == 0)
				continue;
			if(freq[i] % 2 == 0)
			{
				strength++;
				if(min > freq[i])
					min = freq[i];
			}
			else
			{
					flag = 0;
					break;
			}
		}
		if(flag)
		{
			if(strength == 1)
				cout << min / 4 << endl;
			else
				cout << min / 2 << endl;
		}
		else
			cout << "0" << endl;
	}
}