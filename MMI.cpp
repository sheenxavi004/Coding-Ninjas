// Multiplicative modulo inverse of a, m = (a * b) % m = 1, then b is called the Multiplicative Modulo Inverse 
#include <iostream>
using namespace std;

class triplet{
	public:
		int x;
		int y;
		int gcd;
};

//Using Diophatine Equation i.e. extended Euclids algorithms
triplet extendedEuclid(int a, int b)
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
int main()
{
	int a, b;
	cin >> a >> b;
	triplet ans = extendedEuclid(a, b);
	if(ans.gcd == 1)
		cout << ans.x << endl;
	else
		cout << "It doesn't exist" << endl;
	return 0;
}