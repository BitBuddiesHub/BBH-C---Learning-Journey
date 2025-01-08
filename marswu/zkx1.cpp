#include<bits/stdc++.h>
using namespace std;
char a[50],b[50];
int n;
bool prime(int x)
{
	if(x<=1) return false;
	if(x==2) return true;
	for(int i=2;i*i<=x;i++) if(x%i==0) return false;
	return true;
}
int calc(int num)
{
	int ans=0; 
	while(num)
	{
		ans=ans*8+num%10;
		num/=10;
	}
	return ans; 
}
char *work(char *s,char *st)
{
	char *t=st;
	int num=0;
	while(*s)
	{
		if(*s>='0'&&*s<='9') num=num*10+*s-'0';
		else
		{
			if(prime(num))
			{
				while(*s&&(*s<'0'||*s>'9'))
				{
					if(*s>='a'&&*s<='z') *s-=32;
					s++;
				}
				s--;
			}
			else if(prime(calc(num)))
			{
				while(*s&&(*s<'0'||*s>'9'))
				{
					if(*s>='A'&&*s<='Z') *st++=*s+32;
					else *st++=*s;
					s++;
				}
				s--;st--;
			}
			num=0;
		}
		s++;
	}
	return t;
}
char *strcat1(char *s,const char *ct)
{
	char *st=s;
	while(*s) s++;
	while(*s++=*ct++);
	return st;
}
int main()
{
	ofstream ofile;
	ofile.open("test.txt");
	cin>>n>>a;
	ofile<<strcat1(a,work(a,b));
	ofile.close();
	system("pause");
	return 0;
}

