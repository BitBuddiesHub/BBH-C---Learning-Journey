#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;
int main()
{
	int num[20000], sum=0, count;
	float avg, biao, fang, tmp[20000], sum1=0;
	ofstream ofile;
	ofile.open("C:\\Users\\Marsw\\Desktop\\17D24113fileA.txt");
	srand((unsigned)time(0));
	for(int i=0; i<10000; i++)
	{
		num[i]=rand()%400-200;
		sum+=num[i];
	}
	avg=1.0*sum/10000;
	for(int i=0; i<10000; i++)
	{
		tmp[i]=1.0*(num[i]-avg)*(num[i]-avg);
		sum1+=tmp[i];
	}
	fang=1.0*sum1/10000;
	biao=sqrt(fang);
	ofile<<"平均值："<<setprecision(2)<<avg+0.005<<"  "<<"标准差："<<setprecision(2)<<biao+0.005<<endl;
	for(int i=-200; i<=190; i=i+10)
	{
		ofile<<"\n["<<i<<","<<i+10<<"]   ";
		count=0;
		for(int j=0; j<10000; j++)
		{
			if(num[j]>=i&&num[j]<i+10) count++;
		}
		ofile<<count<<endl;
	}
	ofile.close();
	return 0;
}
