#include <iostream>
using namespace std;
int main()
{
	int m, n, resd;
	cout<<"输入两个整数"<<endl;
	cin>>m>>n;
	cout<<"最大公约数为";
	while(true)
	{
		resd=m%n;
		if(resd==0) break;
		m=n;
		n=resd;
	}
	cout<<n;
	return 0;
}
