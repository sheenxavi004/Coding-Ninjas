#include<bits/stdc++.h>
using namespace std;

struct Paint{
    long time, value, weight;
};

bool compare(struct Paint x, struct Paint y)
{
    if(x.time == y.time)
    {
        if(x.value == y.value)
        {
            return x.weight < y.weight;
        }
        return x.value < y.value;
    }
    return x.time < y.time;
}

long solve(struct Paint arr[], long n, long D)
{
    sort(arr, arr + n, compare);
    
    long currD = 0;
    long price = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if(currD + arr[i].weight <= D)
        {
            currD += arr[i].weight;
            price += arr[i].value;
        }
        else{
            long remD = D - currD;
            price += (remD * arr[i].value)/arr[i].weight;
            break;
        }
    }
    return price;
}
int main()
{
    //Write your code here
    long n, d;
    cin >> n >> d;
    struct Paint arr[n];
    for(int i = 0 ; i < n ; i++) 
        cin >> arr[i].time >> arr[i].value >> arr[i].weight;
    cout << solve(arr, n, d) << endl ;
    return 0;
}