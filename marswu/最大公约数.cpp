#include <iostream>
using namespace std;
int gcd(int x,int y)
{
	if(x>y)
	{
		int t=x;
		x=y;
		y=t;
	}
	if(x==0) return y;
	return gcd(x,y%x);
}
int main()
{
	int a,b;
	cin>>a>>b;
	cout<<gcd(a,b);
	return 0;
}
