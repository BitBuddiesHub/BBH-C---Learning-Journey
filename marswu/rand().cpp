#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	srand((unsigned)time(0));
	int a=rand()%10;
	cout<<a<<endl;
	return 0;
}
