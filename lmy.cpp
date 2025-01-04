//1
#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

int prime(int[]);
void convert(int[],char[],int);
void dechar(char[]);

int main(){
    int num[200],number;
    char str[200];
//2
    cout<<"100到255的素数是:"<<endl;
    number=prime(num);
    cout<<"\n总共"<<number<<"个\n";

//3
    convert(num,str,number);
    cout<<"所有素数对应的十六进制数位以字符形式依次连接生成的字符串是：\n";
    cout<<str<<endl;

//4
    dechar(str);
    cout<<"\n删除数字字符后的字符串是:\n";
    cout<<str<<endl;

//5
    ofstream ofile("111.txt");
    ofile<<str<<endl;
    ofile.close();

    system("pause");
    return 0;
//6
}
int prime(int num[]){
//7
    int count=0,j;
    for(int i=100;i<255;i++){
        int k=sqrt((double)i);
        for(j=2;j<=k;j++){
            if(i%j==0)break;
        }
            if(j>k){
                num[count]=i;
                cout<<i<<'\t';
                if(count%10==9)cout<<'\n';
                count++;
            }
        
    }
    return count;
}

void convert(int num[],char str[],int N){
    int subscript=0;
    for(int i=0;i<N;i++){
        for(int j=1;j>=0;j--){
            if(num[i]%16<10)
            str[subscript+j]=num[i]%16+'0';
            else
            str[subscript+j]=(num[i]%16-10)+'A';
        num[i]=num[i]/16;
        }
        subscript=subscript+2;
    }
    str[subscript]='\0';
}

void dechar(char str[]){
    int len=0;
    while(str[len]!='\0'){
        ++len;
    }
    int index=0;
    for(int i=0;i<len;++i){
        if(!(str[i]>='0'&&str[i]<='9')){
            str[index]=str[i];
            ++index;
        }
    }
    str[index]='\0';
}