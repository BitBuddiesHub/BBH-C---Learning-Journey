#include <iostream>
using namespace std;

const int lies = 3;
const int hang = 3;
int main()
{
	int matrix[lies][hang]={1, 2, 3, 4, 5 ,6 ,7 ,8 ,9};
	int middle[lies][hang]={0};
	for (int i=0; i<lies; i++)
	{
		for(int j=0; j<hang; j++)
		{
			cout << matrix[i][j];
		}
		cout<<endl;
	}
	for (int i=0; i<hang; i++)
	{
		for(int j=0; j<lies; j++)
		{
			middle[j][lies-1-i]=matrix[i][j];
		}
	}
	for (int i=0; i<lies; i++)
	{
		for(int j=0; j<hang; j++)
		{
			cout << middle[i][j];
		}
		cout<<endl;
	}
	return 0;
}
