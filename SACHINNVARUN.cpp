#include <iostream>
using namespace std;

typedef long long ll;

class triplet{
	public:
		ll x;
		ll y;
		ll gcd;
};

//Using Diophatine Equation i.e. extended Euclids algorithms
triplet extendedEuclid(ll a, ll b)
{
	if(b == 0)
	{
		triplet ans;
		ans.gcd = a;
		ans.x = 1;
		ans.y = 0;
		return ans;
	}
	triplet smallAns = extendedEuclid(b, a % b);
	triplet ans;
	ans.gcd = smallAns.gcd;
	ans.x = smallAns.y;
	ans.y = smallAns.x - (a/b) * smallAns.y;
	return ans;
}
ll MMI(ll a, ll b)
{
	ll X = extendedEuclid(a, b).x;
	return (X % b + b) % b;
}

ll gcd(ll a, ll b)
{
	if(b == 0)
		return a;
	return gcd(b, a % b);
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		ll a, b, d;
		cin >> a >> b >> d;
		ll g = gcd(a, b);
// d is not multiple of gcd of a, b
		if(d % g)
		{
			cout << 0 << endl;
			continue;
		}
// If d is zero then the only pair is 0,0
		if(d == 0)
		{
			cout << 1 << endl;
			continue;
		}
		a /= g;
		b /= g;
		d /= g;

		ll multinv = MMI(b, a);
		ll smallAns = ((d % a) * multinv) % a;
// Only Positive values can exist
		if(d < smallAns * b)
		{
			cout << 0 << endl;
			continue;
		}
		int ans = ((d / b) - smallAns)/a;
		cout << ans + 1 << endl;
	}
	return 0;
}