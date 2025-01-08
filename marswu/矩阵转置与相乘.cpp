#include <iostream>
#include <iomanip>
using namespace std;

void inverse(int matrix1[3][6], int middle[6][3]) //矩阵转置
{
	int i, j;
	for (i=0; i<3; i++)
	{
		for(j=0; j<6; j++)
		{
			middle[j][i]=matrix1[i][j];
		}
	}
	return;
}

void multi(int middle[6][3], int matrix2[3][4], int result[6][4])
{
	int i, j, k;
	for(i=0; i<6; i++)
	{
		for(j=0; j<4; j++)
		{
			result[i][j]=0;
			for(k=0; k<3; k++)
			{
				result[i][j]+=middle[i][k]*matrix2[k][j];
			}
		}
	}
	return;
}

void output(int result[6][4])
{
	int i, j;
	cout<<"result"<<'\n';
	for(i=0; i<6; i++)
	{
		for(j=0; j<4; j++)
		{
			cout<<setw(6)<<result[i][j];
		}
	}
	return;
}

int main()
{
	int middle[6][3], result[6][4];
	int matrix1[3][6]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
	int matrix2[3][4]={2,4,6,8,10,12,14,16,18,20,22,24};
	inverse(matrix1, middle);
	multi(middle, matrix2, result);
	output(result);
	return 0;
}
