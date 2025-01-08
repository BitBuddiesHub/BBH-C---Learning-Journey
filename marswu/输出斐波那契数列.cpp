#include <iostream>
#include <iomanip>
using namespace std;
int count;
int fib(int n)
{
	count++;
	if(n==0) return 0;
	else if(n==1) return 1;
	else return fib(n-1)+fib(n-2);
}
	 
int main()
{
	int i;
	for(i=0; i<=15; i++)
	{
		cout<<setw(6)<<fib(i);
		if(i%5==0) cout<<endl;
	}
	cout<<count;
	return 0;
}
