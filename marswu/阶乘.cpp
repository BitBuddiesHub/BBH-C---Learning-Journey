#include <iostream>
using namespace std;

int fac(int n)
{
	int y;
	cout<<n<<'\t';
	if(n==0||n==1) y=1;
	else y=n*fac(n-1);
	cout<<y<<'\t';
	return y;
}
int main()
{
	cout<<fac(4)<<endl;
	return 0;
}
