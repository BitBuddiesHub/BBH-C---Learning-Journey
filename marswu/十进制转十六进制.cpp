//十进制转十六进制
#include <iostream>
using namespace std;
int main()
{
	int dec[10];
	int n=28, count=0;
	for(int i=0; i<6; i++)
	{
		dec[i]=n%16;
		n/=16;
		count++;
		if(n==0) break;
	}
	for(int j=count-1; j>=0; j--)
	{
		if(dec[j]>=0&&dec[j]<=9) cout<<dec[j];
		else cout<<char(dec[j]-10+'A');
	}
	return 0;
}

