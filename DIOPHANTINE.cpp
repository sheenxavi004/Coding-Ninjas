#include <iostream>
using namespace std;

class triplet{
	public:
		int x;
		int y;
		int gcd;
};

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
	cout << ans.x << " " << ans.y << " " << ans.gcd;
	return 0;
}