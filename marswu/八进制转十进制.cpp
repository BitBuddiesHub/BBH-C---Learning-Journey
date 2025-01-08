// 八进制转十进制  12345
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int count=0, result=0;
	int oct[5];
	cout<<"输入5位八进制序列"<<endl;
	for(int i=0; i<5; i++)
	{
		oct[i]=cin.get()-'0';
	}
	for(int j=4; j>=0; j--)
	{
		cout<<oct[j]<<" ";
		result+=oct[j]*pow(8,count);
		count++;
	}
	cout<<result;
	return 0;
}
