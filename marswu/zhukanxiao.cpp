#include <iostream>
using namespace std;
void change(int,int);
int main()
{
	int x,m;
	cin>>x>>m;
	change(x,m);
	return 0;
}
void change(int x,int m)
{
	int a[1000], count=0;
	for (int i=0;i<=1000;i++)
	{
		a[i]=x%m;
		x/=m;
		count++;
		if (x==0) break; 
	}
	
	for(int j=count-1; j>=0; j--)
	{
		cout<<a[j];
	}
	return;

}
