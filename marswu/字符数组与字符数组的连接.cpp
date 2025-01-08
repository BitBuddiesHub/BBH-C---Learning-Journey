#include <iostream>
using namespace std;

void strcat(char s[], char ct[])
{
	int i=0, j=0;
	while (s[i]!=0) i++; //找到s数组的末尾
	while (ct[j]!=0) s[i++]=ct[j++]; //ct数组的数据连接到s数组的尾部
	s[i]='\0'; //加串结束符
}

int main()
{
	char a[40]="朱衎霄";
	char b[40]="是男娘";
	strcat(a, b);
	cout<<a<<endl;
	return 0;
}
