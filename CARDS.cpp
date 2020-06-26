#include <iostream>
#include <utility>
#include <vector>
using namespace std;

vector<pair<int, int>> factorize(int n)
{
	vector<pair<int, int>> factors;
	for(int i = 2 ; i <= n; i++)
	{
		int count = 0;
		while(n % i == 0)
		{
			count++;
			n /= i;
		}
		if(count > 0)
			factors.push_back(make_pair(i, count));

	}
	return factors;
}

void addFactors(int n, vector<pair<int, int>> &Vq)
{
	for(auto it = Vq.begin(); it != Vq.end() && n > 1 ; it++)
	{
		int div = it -> first;
		while(n % div == 0)
		{
			(it -> second)++;
			n /= div;
		}
	}
}


void removeFactors(int n, vector<pair<int, int>> &Vq)
{
	for(auto it = Vq.begin(); it != Vq.end() && n > 1 ; it++)
	{
		int div = it -> first;
		while(n % div == 0)
		{
			(it -> second)--;
			n /= div;
		}
	}	
} 

bool isValid(vector<pair<int, int>> Vp, vector<pair<int, int>> Vq)
{
	for(auto ip = Vp.begin(), iq = Vq.begin(); ip != Vp.end() && iq != Vq.end() ; ip++, iq++)
	{
		int freqp = ip -> second, freqq = iq -> second;
		if(freqq < freqp)
			return false;
	}

	return true;
}

int main()
{
	int n, k;
	cin >> n >> k;
	int arr[n];
	for(int i = 0 ; i < n ; i++)
		cin >> arr[i];

	vector<pair<int, int>> Vp = factorize(k);
	vector<pair<int, int>> Vq;

	//Initializing the vector which keeps track of the necessary prime factors of k available as the product of the array elements
	for(auto it = Vp.begin(); it != Vp.end() ; it++)
		Vq.push_back(make_pair((it -> first), 0));

	int i = 0, j = 0;
	long count = 0;
	addFactors(arr[0], Vq);
	while(i < n && j < n)
	{
		if(isValid(Vp, Vq))
		{
			count += (n - i);
			removeFactors(arr[j], Vq);
			j++;
		}
		else
		{	
			i++;
			addFactors(arr[i], Vq);
		}
	}

	cout << count << endl;

	return 0;
}