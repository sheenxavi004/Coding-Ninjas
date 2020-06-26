#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define mod 1000000007
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        long sum = 0;
        cin >> n >> k;
        
        int *dp = new int[n];
        dp[0] = 1;
        for(int i = 0 ; i <= k ; i++)
            dp[0] = (dp[0] % mod * (1 + i) % mod) % mod;
        for(int i = 1 ; i < n ; i++)
            dp[i] = ((dp[i - 1] % mod) * (i + k + 1)) / i;
        
        for(int  i = 0 ; i < n ; i++)
            sum = (sum % mod + dp[i] % mod) % mod;
        
        cout << sum << endl;
    }
    return 0;
}