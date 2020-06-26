#include<bits/stdc++.h>
using namespace std;

class coder{
	public:
		int x, y, index;
};

bool compare(coder A, coder B)
{
	if(A.x == B.x)
		return A.y < B.y;
	return A.x < B.x;
}

void update(int y, int * bit)
{
	for( ; y <= 300000; y += (y & (-y)))
		bit[y]++;
}

int query(int y, int * bit){
	int count = 0;
	for(; y > 0 ; y -= (y & (-y)))
		count += bit[y];

	return count;
}
int main()
{
	int n;
	cin >> n;

	coder * arr = new coder[n];
	for(int i = 0 ; i < n ; i++){
		cin >> arr[i].x >> arr[i].y;
		arr[i].index = i;
	}

	sort(arr, arr + n, compare);

	int * bit = new int[300001]();
	int * ans = new int[n];

	for(int i = 0 ; i < n ; i++)
	{
		int endIndex = i;

		while(endIndex < n && arr[i].x == arr[endIndex].x && arr[i].y == arr[endIndex].y)
			endIndex++;

		//query
		for(int j = i; j < endIndex ; j++)
			ans[arr[j].index] = query(arr[j].y, bit);

		//update
		for(int j = i; j < endIndex ; j++)
			update(arr[j].y, bit);
	}
	
	for(int i = 0 ; i < n ; i++)
		cout << ans[i] << endl;

 	return 0;
}