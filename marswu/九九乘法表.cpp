#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int i, j;
	cout<<setw(3)<<'*'<<setw(4)<<' ';
	for (i=1; i<10; i++) cout<<setw(4)<<i;
	cout<<endl<<endl;
	for(i=1; i<10; i++)
	{
		cout<<setw(3)<<i<<setw(4)<<' ';
		for(j=1; j<=i; j++)
		{
			cout<<setw(4)<<i*j;
		}
		cout<<endl;
	}
	return 0;
}
