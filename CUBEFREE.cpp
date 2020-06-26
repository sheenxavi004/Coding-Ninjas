#include <iostream>
using namespace std;

#define MAX 1000001

void cubeFree(int * cubefree, int n)
{
	int cube = n * n * n;
	for(int i = cube ; i <= MAX ; i += cube)
		cubefree[i] = 0;
}
int main()
{
	int t;
	cin >> t;
	int * cubefree = new int[MAX];
	for(int i = 0 ; i < MAX ; i++)
		cubefree[i] = 1;

	for(int i = 2 ; (i * i * i) < MAX ; i++)
		if(cubefree[i])
			cubeFree(cubefree, i);

	int count = 0;
	for(int i = 0 ; i < MAX ; i++)
		if(cubefree[i])
			cubefree[i] = count++;

	int k = 0;	
	while(t--)
	{
		k++;
		int n;
		cin >> n;
		if(cubefree[n])
			cout << "Case " << k << ":" << cubefree[n] << endl;
		else
			cout << "Case " << k << ":" << "Not Cube Free" << endl;
	}
	return 0;
}