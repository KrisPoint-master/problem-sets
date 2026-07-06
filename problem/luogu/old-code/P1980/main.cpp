#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        int b=i;
        while(b!=0){ // xun huan qiu wei
            if(b % 10 == x){
                sum++;
            }
            b = b / 10; // yi wei yi wei
        }
    }
    cout<<sum;
    return 0;
}