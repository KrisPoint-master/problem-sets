#include<bits/stdc++.h>
using namespace std;
bool isprime(int x){
    if(x <= 1) return 0;
    for(int i=2;i*i<=x;i++){
        if(x%i==0) return false;
    }
    return true;
}
int main(){
    int n,a;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        if(isprime(a))
            cout<<a<<" ";   
    }
    return 0;
}
