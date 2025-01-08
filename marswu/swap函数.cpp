#include <iostream>
using namespace std;

void swap(int &a, int b)
{
	int t=a;
	a=b;
	b=t;
	cout<<a<<b<<endl;
	return;
}

int main()
{
	int a=1, b=2;
	swap(a, b);
	cout<<a<<b;
	return 0;
}
