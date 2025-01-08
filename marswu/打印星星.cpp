#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int i, j;
	for(i=1; i<=5; i++)
	{
		for(j=1; j<=5-i; j++) cout<<" ";
		for(j=1; j<=11; j++) cout<<"*";
		cout<<endl;
	}
	return 0;
}
