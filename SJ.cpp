#include<bits/stdc++.h>
using namespace std;
int main() {

	// Write your code here
    int x;
    cin >> x;
    int i = 0;
    int jumps = 0;
    while(i < x)
    {
        jumps++;
        i += jumps;
    }
    if((x - i) & 1)
        jumps++;
    cout << jumps << endl;
    return 0;
}