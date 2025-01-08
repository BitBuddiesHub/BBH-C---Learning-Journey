#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{
	srand((unsigned)time(0));
	int a=rand()%3+1;//b~a+b-1
	cout<<a;
	return 0;
}