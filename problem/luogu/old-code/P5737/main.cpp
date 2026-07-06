#include<bits/stdc++.h>
using namespace std;
int ans[1500];
int main(){
    int b,e;
    cin>>b>>e;
    int cnt=0;
    for(int i=b;i<=e;i++){
        if(((i%4==0)&&(i%100!=0))||(i%400==0)){
            ans[cnt++]=i;
        }
    }
    cout<<cnt<<endl;
    for(int i=0;i<cnt;i++) cout<<ans[i]<<" ";
    return 0;
}

