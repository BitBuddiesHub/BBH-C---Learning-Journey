#include <iostream>
using namespace std;
int main()
{
	int fib[20]={1, 1}, count=0;
	for(int i=2; i<20; i++)
	{
		fib[i]=fib[i-2]+fib[i-1];
	}
	for(int i=0; i<20; i++)
	{
		cout<<fib[i]<<"\t";
		count++;
		if(count%5==0) cout<<endl;
	}
	return 0;
}
