#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
	int k, i;
	k=int(sqrt(double(n)));
	for(i=2; i<=k; i++)
	{
		if(n%i==0) return false;
	}
	return true;
}


int main()
{
	int n;
	cout<<"请输入两位数n:"<<endl;
	cin>>n;
	if(isPrime(n)) cout<<n<<"是素数";
	else cout<<n<<"不是素数";
	return 0;
}
