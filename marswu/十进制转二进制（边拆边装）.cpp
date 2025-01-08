#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int n, p, q=0 , count = 0;
	cin>>n;
	while(n>0){
		p = n % 2;
		q += p * pow(10, count);
		count++;
		n=n/2;  
	}
	cout<<q;
}