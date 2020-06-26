#include<bits/stdc++.h>
using namespace std;

void subseq(string input, string output)
{
	if(input.length() == 0)
	{
		cout << output << endl;
		return ; 
	}
	subseq(input.substr(1),output + input[0]);
	subseq(input.substr(1), output);
}
int main()
{
	string str;
	cin >> str;
	subseq(str,"");
	return 0;
}