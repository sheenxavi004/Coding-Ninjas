#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string code;
		int sa, sb;
		cin >> code >> sa >> sb;
		int ia = 0, ib = 0;
		int len = code.length();
		int flag = 0;
		for(int i = 0; i < len ; i++)
		{
			if(code[i] == 'A')
				ia = i;
			if(code[i] == 'B')
				ib = i;
		}
		while(true)
		{
			if(ia == ib)
			{
				flag = 1;
				break;
			}

			if(ia >= len || ib < 0)
			{
				break;
			}

			ia += sa;
			ib -= sb;
		}

		if(flag)
			cout << "unsafe" << endl;
		else
			cout << "safe" << endl;

	}
	return 0;
}