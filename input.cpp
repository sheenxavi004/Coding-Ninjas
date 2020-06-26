#include<bits/stdc++.h>
using namespace std;

struct Paint long{
    long long time, value, weight;
};

bool checkLiable(Paint worker1, Paint worker2)
{
    if(worker1.weight == worker2.weight)
        return worker1.value > worker2.value;
    return worker1.weight < worker2.weight;
}
bool compare(struct Paint x, struct Paint y)
{
    if(x.time == y.time)
    {
        if(x.weight == y.weight)
        {
            return x.value < y.value;
        }
        return x.weight > y.weight;
    }
    return x.time < y.time;
}

long long solve(struct Palong long arr[], long long n, long long D)
{
    sort(arr, arr + n, compare);
    /*for(long long i = 0 ; i < n ; i++)
    {
        cout << arr[i].time << " " << arr[i].value << " " << arr[i].weight << endl;
    }*/
    long long currD = 0;
    long long price = 0;
    bool truth[n];
    for(long long i = 0 ; i < n ; i++)
        truth[i] = false;
    long long pos = 0;
    struct Paint worker = arr[0];
    for(long long i = 0 ; i < n ; i++)
    {
        if(currD == D)
            break;

        if(checkLiable(worker, arr[i]))
        {
               worker = arr[i];
               pos = i;
        }
        if(currD + worker.weight <= D)
        {
            currD += worker.weight;
            if(!truth[pos])
            {
                price += worker.value;
                truth[pos] = true;
            }
        }
        else
        {
            currD = D;
            if(!truth[pos])
            {
                price += worker.value;
                truth[pos] = true;
            }
            break;
        }
    }
    return price;
}
int main()
{
    //Write your code here
    long long n, d;
    cin >> n >> d;
    struct Paint arr[n];
    for(long long i = 0 ; i < n ; i++) 
        cin >> arr[i].time >> arr[i].value >> arr[i].weight;
    cout << solve(arr, n, d) << endl ;
    return 0;
}