#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
//求2-100之间的全部素数
int main() {
    int m, k, i, n=0;
    for (m=2; m<=100; m++)
    {
    	k=int(sqrt(double(m)));
    	for(i=2; i<=k; i++)
    	{
    		if(m%i==0) break;
		}
		if (i>k)
		{
			n++;
			cout<<setw(4)<<m;
			if(n%5==0) cout<<endl;
		}
		
	}
	cout<<"素数有"<<n<<"个";
    return 0;
}