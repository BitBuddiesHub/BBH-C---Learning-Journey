//输入一个8位二进制数,将其转换为十进制数输出
#include <iostream>
#include <cmath>
using namespace std;

int trans(int n)
{
	int bin[20];
	for(int i=0; i<8; i++)
	{
		bin[i]=n%10;
		n/=10;
	}
	
	int result, count=0;
	for(int j=0; j<8; j++)
	{
		result+=bin[j]*pow(2, count);
		count++;
	}
	return result;
}
int main()
{
	int n;
	cin>>n;
	cout<<trans(n)<<endl;
	return 0;
}
