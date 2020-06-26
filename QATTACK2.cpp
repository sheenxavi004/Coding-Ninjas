#include<bits/stdc++.h>
using namespace std;

int queensAttack(int n, int r_q, int c_q, bool** obstacles) {
    int count = 0;
    for(int i = r_q + 1; i < n ; i++)
    {
        if(obstacles[i][c_q])
            break;
        count++;
    }
    for(int i = r_q - 1; i >= 0 ; i--)
    {
        if(obstacles[i][c_q])
            break;
        count++;
    }
    for(int i = c_q + 1 ; i < n ; i++)
    {
        if(obstacles[r_q][i])
            break;
        count++;
    }
    for(int i = c_q - 1; i >= 0 ; i--)
    {
        if(obstacles[r_q][i])
            break;
        count++;
    }
    for(int i = r_q + 1, j = c_q + 1 ; i < n && j < n ; i++, j++)
    {
        if(obstacles[i][j])
            break;
        count++;
    }
    for(int i = r_q - 1, j = c_q - 1 ; i >= 0 && j >= 0 ; i--, j--)
    {
        if(obstacles[i][j])
            break;
        count++;
    }
    for(int i = r_q + 1, j = c_q - 1 ; i < n && j >= 0 ; i++, j--)
    {
        if(obstacles[i][j])
            break;
        count++;
    }
    for(int i = r_q - 1, j = c_q + 1 ; i >= 0 && j < n ; i--, j++)
    {
        if(obstacles[i][j])
            break;
        count++;
    }

    return count;
}
int main()
{
	int n, k;
	cin >> n >> k;

	bool **obstacles = new bool * [n];
	for(int i = 0 ; i < n ; i++)
		obstacles[i] = new bool[n]();
	memset(obstacles, 0, sizeof(bool) * n * n);
	int r_q, c_q;
	cin >> r_q >> c_q;
	while(k--)
	{
		int r, c;
		cin >> r >> c;
		obstacles[r - 1][c - 1] = 1;
	}
	
	cout << queensAttack(n, r_q - 1, c_q - 1, obstacles) << endl;
	return 0;
}