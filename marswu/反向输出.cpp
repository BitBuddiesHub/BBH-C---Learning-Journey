#include <iostream>
using namespace std;
void backward(int);

int main()
{
	int n;
	cin>>n;
	cout<<n<<endl;
	backward(n);
	cout<<n;
	return 0;
}

void backward(int &n)
{
	cout<<n/10;
	if(n<10) return;
	
}


