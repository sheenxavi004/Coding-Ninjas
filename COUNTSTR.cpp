#include<bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	cin >> str;
	int arr[26];

	for(int i = 0 ; i < 26 ; i++)
		arr[i] = 0;
	int len = str.length();
	for(int i = 0 ; i < len ; i++)
		arr[str[i] - 65]++;

	char set[len];
	for(int i = 0 ; i < len ; i++)
	{
		int k = str[i] - 65;
		for(int j = k - 1 ; j >= 0 ; j--)
	}
	return 0;
}