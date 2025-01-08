//十进制转八进制 64
#include <iostream>
using namespace std;
int main()
{
	int n, count=0, oct[10];
	cout<<"输入十进制数"<<endl;
	cin>>n;
	for(int i=0; i<10; i++)
	{
		oct[i]=n%8;
		n/=8;
		count++;
		if(n==0) break;
	}
	cout<<count<<endl;
	bool flag=true;
	//0010
	for(int j=count; j>=0; j--)
	{
		if(oct[j]==0&&flag==true) continue;
		if(oct[j]!=0) flag=false;
		cout<<oct[j];
	}
	return 0;
}
