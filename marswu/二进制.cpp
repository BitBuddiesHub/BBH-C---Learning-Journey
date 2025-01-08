#include<bits/stdc++.h>

using namespace std;

void work(int num, int now0, int now1, int &ans0, int &ans1) {
    if(num==0) {
        ans0+=(now0>=now1);
        ans1+=(now0<now1);
        return;
    }
    if (num%2==0) work (num/2, now0+1, now1, ans0, ans1);
    else work (num/2, now0, now1+1, ans0, ans1);
    return;
}

int main() {
    int ans0=0, ans1=0;
    for(int i=1;i<=100;i++) {
        work(i,0,0,ans0, ans1);
    }
    cout<<ans0<<" "<<ans1<<endl;
    return 0;
}