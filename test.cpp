#include <iostream>
using namespace std;

int ghost(int n, int k, int mask)
{
    if(mask == ((1 << n) - 1))
    {
       return 1;
    }
    
    int count = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if(!(mask & (1 << i)))
        {
        	if(k > 0)
        	{
	            if(((k + 1) & (i + 1)) == (k + 1))
	            {
	                if(k < i)
	                    count += ghost(n, k + 1, (mask | (1 << i)));
	            }
	 			else
	            	count += ghost(n, k + 1, (mask | (1 << i)));
        	}
 			else
	            count += ghost(n, k + 1, (mask | (1 << i)));
        }
    }
    return count;
}
int main()
{
    int n;
    cin >> n;
    cout << ghost(n, 0, 0) << endl;
    return 0;
}