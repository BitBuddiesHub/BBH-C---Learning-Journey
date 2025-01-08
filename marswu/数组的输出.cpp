#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int array[20];
	array[0]=1;
	array[1]=2;
	array[2]=3;
	for(int i=0; i<=2; i++)
	{
		cout<<setw(4)<<array[i];
	}
	return 0;
}
