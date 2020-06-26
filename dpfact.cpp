    if(arr[i] + 2 - 1 < m && Y1 + 1 < n && graph[arr[i] + 2 - 1][Y1 + 1] != -1)
    {
        int value = graph[arr[i] + 2 - 1][Y1 + 1];
        edges[i].push_back(value);
    }
    if(arr[i] + 2 - 1 < m && Y1 - 1 < n && graph[arr[i] + 2 - 1][Y1 - 1] != -1)
    {
        int value = graph[arr[i] + 2 - 1][Y1 - 1];
        edges[i].push_back(value);
    }
    if(arr[i] - 2 - 1 < m && Y1 + 1 < n && graph[arr[i] - 2 - 1][Y1 + 1] != -1)
    {
        int value = graph[arr[i] - 2 - 1][Y1 + 1];
        edges[i].push_back(value);
    }
    if(arr[i] - 2 - 1 < m && Y1 - 1 < n && graph[arr[i] - 2 - 1][Y1 - 1] != -1)
    {
        int value = graph[arr[i] - 2 - 1][Y1 - 1];
        edges[i].push_back(value);
    }
    if(arr[i] + 1 - 1 < m && Y1 + 2 < n && graph[arr[i] + 1 - 1][Y1 + 2] != -1)
    {
        int value = graph[arr[i] + 1 - 1][Y1 + 2];
        edges[i].push_back(value);
    }
    if(arr[i] + 1 - 1 < m && Y1 - 2 < n && graph[arr[i] + 1 - 1][Y1 - 2] != -1)
    {
        int value = graph[arr[i] + 1 - 1][Y1 - 2];
        edges[i].push_back(value);
    }
    if(arr[i] - 1 - 1 < m && Y1 + 2 < n && graph[arr[i] - 1 - 1][Y1 + 2] != -1)
    {
        int value = graph[arr[i] - 1 - 1][Y1 + 2];
        edges[i].push_back(value);
    }
    if(arr[i] - 1 - 1 < m && Y1 - 2 < n && graph[arr[i] - 1 - 1][Y1 - 2] )
    {
        int value = graph[arr[i] - 1 - 1][Y1 - 2];
        edges[i].push_back(value);
    }  