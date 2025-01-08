#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	int arr[20], count;
	srand((unsigned)time(0));
	for (int i=0; i<20; i++)
	{
		arr[i]=rand()%100;
		cout<<arr[i]<<"\t";
		count++;
		if(count%5==0) cout<<endl;
	}
	int max=arr[0], min=arr[0];
	for(int i=0; i<20; i++)
	{
		if (arr[i]>max) max=arr[i];
		if (arr[i]<min) min=arr[i];
	}
	cout<<"最小值为"<<min<<"最大值为"<<max;
	return 0;
}
