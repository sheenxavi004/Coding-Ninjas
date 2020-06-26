int minOperations(vector<int> arr, int threshold, int d) {

    int n = arr.size();
    map<int,int[2]> counter;
    int minCount = INT_MAX;
    for(int i = 0 ; i < n ; i++)
    {
        int temp = arr[i];
        int count = 0;
        while(temp > 0)
        {
            counter[temp][0]++;
            counter[temp][1] += count;
            if(count[temp][0] >= threshold)
                minCount = min(minCount, count[temp][1]);
            temp /= d;
            count++;
        }
        counter[temp][0]++;
        counter[temp][1] += count;
    }
    return minCount;
}