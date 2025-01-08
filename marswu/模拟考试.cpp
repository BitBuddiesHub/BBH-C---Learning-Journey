// 补充1 Begin（5分）: 必要的头文件
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

// 补充1 End
int  prime(int[]);
void convert(int[], char[], int);
void dechar(char[]);

int main() {

    int num[200], number; //number保存素数个数
    char str[200];

    // 补充2 Begin（5分）
    // 调用函数实现100~255之间素数的查找、保存(存入数组num)和输出, 并获取素数的个数
   



    // 补充2 End

    // 补充3 Begin（5分） 
//调用函数将数组num中保存的所有素数的16进制数位以字符形式依次连续存入字符数组str
 //中生成字符串
   





    // 补充3 End

    // 补充4 Begin（5分）: 调用函数删除字符数组str中字符串的数字字符
   




    // 补充4 End
    
    // 补充5 Begin（15分）: 把删除数字字符后的字符串写入"学号.txt"文件, 最后关闭文件
   



    // 补充5 End
    system("pause");
    return 0; }
int prime(int num[]) {
// 补充6 Begin（25分）
// 查找100~255之间的所有素数, 存入整型数组num中, 并返回素数的个数
// 将所有素数按照每行10个数据输出，数据之间以空格'\t'隔开
for(int n=100; n<256; n++)
{
	int k=sqrt(double(n)), count;
	for(int i=2; i<=k; i++)
	{
		if(n%k==0) break;
	}
	if (k>i)
	{
		num[count]=n;
		cout<<n<<'\t';
		if (count%5==0) cout<<endl;
		count++;
	}
	return count;
}







// 补充6 End
}

void convert(int num[], char str[], int N) {
// 补充7 Begin（25分）
// 将数组num中保存的所有素数的16进制数位以字符形式依次连续存入字符数组str中生成字符串
// 例如107、109这两个素数对应的16进制数为6B、6D, 存入字符数组的内容为"6B6D"
  









// 补充7 End
}

void dechar(char str[]) {
// 补充8 Begin（15分）
// 删除字符数组str中字符串的数字字符, 例如数组str中的初始字符串为"A1B2C3" 
// 操作后数组str中的字符串变为"ABC"
   




// 补充8 End
}

