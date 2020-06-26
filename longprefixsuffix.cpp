#include<iostream>
using namespace std;

int * lps(string str)
{
	int len = str.length();
	int i = 1 , j = 0;
	int * arr = new int[len];

	arr[0] = 0;
	while(i < len)
	{
		if(str[i] == str[j])
		{
			arr[i] = j + 1;
			i++;
			j++;
		}
		else
		{
			if(j != 0)
				j = arr[j - 1];
			else
			{
				arr[i] = 0;
				i++;
			}
		}
	}

	return arr; 
}

int kmp(string str, string pat)
{
	int * lp = lps(pat);
	int lenS = str.length();
	int lenT = pat.length();

	int i = 0, j = 0;
	while(i < lenS && j < lenT)
	{
		if(str[i] == pat[j])
		{
			i++;
			j++;
		}
		else
		{
			if(j != 0)
				j = lp[j - 1];
			else
				i++;
		}
	}

	if(j == lenT)
		return i - j;
	return -1;
}
int main()
{
	string str, pat;
	cin >> str >> pat;

	cout << kmp(str, pat) << endl;
	return 0;
}