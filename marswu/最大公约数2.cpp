#include <iostream>
using namespace std;
int f[50][50];
//f[i][j] (i<=j):i j的最大公约数
//任意一个数和0的最大公约数都是它本身
int main()
{
	int a,b;
	cin>>a>>b;
	if(a>b)
	{
		int t=a;
		a=b;
		b=t;
	}
	for(int i=0;i<=b;i++) f[0][i]=i;
	for(int i=1;i<=a;i++)
	{
		for(int j=i;j<=b;j++)
		{
			if(i<=j%i) f[i][j]=f[i][j%i];
			else f[i][j]=f[j%i][i];
			cout<<i<<" "<<j<<":"<<f[i][j]<<endl;
		}
	}
	//gcd(i,j)=gcd(i,j%i)
	//f[i][j] = f[j%i][i] / f[i][j%i]
	cout<<f[a][b];
	return 0;
}
