#include <iostream>
using namespace std;

const int n=8;

int main()
{
	char bin[n];
	int x=2, a, dec, i;
	cout<<"输入二进制序列"<<endl;
	cin>>bin;
	dec=0;int now=1;
	for(i=n-1; i>=0; i--) //1 0 1 1 0 1 0 1
	{
		a=bin[i]-'0';//a=1 0 1 0 1
		dec+=a*now;// dec=1 2 5 10 21
		now*=2;
//		cout<<dec<<endl;
	}
	cout<<dec;
	return 0;
}
