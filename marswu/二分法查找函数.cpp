#include <iostream>
#include <algorithm>
using namespace std;
int BSearch(int a[], int x)
{
	int left=0, right=9;
	while(right>=left)
	{
		int mid=(left+right)/2;
		cout<<mid<<" ";
		if(a[mid]<x) left=mid+1;
		else if(a[mid]>x) right=mid-1;
		else return mid; 
	}
	if(left>right) return -2;
}
int main()
{
	int arr[10]={2, 4, 6, 8, 20, 10, 30, 50, 40, 60};
	int x;
	cin>>x;
	for(int i=0;i<10;i++) arr[i]=-arr[i];
	sort(arr,arr+10);
	for(int i=0;i<10;i++) arr[i]=-arr[i];
//	for(int i=0;i<10;i++)
//	{
//		for(int j=i+1;j<10;j++)
//		{
//			if(arr[i]>arr[j])
//			{
//				int t=arr[i];
//				arr[i]=arr[j];
//				arr[j]=t;
//			}
//		}
//	}
	for(int i=0;i<10;i++) cout<<arr[i]<<" ";
	cout<<endl;
	int a=BSearch(arr, x);
	cout<<"\n"<<x<<"在第"<<a+1<<"个";
	return 0;
}
