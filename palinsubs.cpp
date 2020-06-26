#include<bits/stdc++.h>
using namespace std;

int lpsubs(string str){
	
	int max = 0;
	int n = str.length();

	for(int i = 0 ; i < n ; i++)
	{
		// Even Length
		int l = i;
		int r = i;
		while(l >=0 && r < n && str[l] == str[r])
		{
			int curr_l = r - l + 1;
			if(curr_l > max){
				max = curr_l;
			}
			l--;
			r++;
		}

		// Odd Length
		l = i;
		r = i + 1;
		while(l >= 0 && r < n && str[l] == str[r])
		{
			int curr_l = r - l + 1;
			if(curr_l > max)
				max = curr_l;
			l--;
			r++;
		}
	}

	return max;
}
int main()
{
	string str;
	cin >> str;
	cout <<	lpsubs(str) << endl;
	return 0;
}