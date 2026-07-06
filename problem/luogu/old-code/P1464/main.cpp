#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[25][25][25];

ll comp(ll a, ll b, ll c){
    if (a<=0||b<=0||c<=0) return 1;
    if(a>20||b>20||c>20){
        dp[20][20][20] = comp(20, 20, 20);
        return dp[20][20][20];
    }
    if (dp[a][b][c] !=0) return dp[a][b][c];
    if(a<b && b<c) {
        dp[a][b][c] = comp(a,b,c-1)+comp(a,b-1,c-1)-comp(a,b-1,c);
        return dp[a][b][c];
    }
    else{
        dp[a][b][c] = comp(a-1, b, c)+comp(a-1, b-1, c)+comp(a-1, b, c-1)-comp(a-1, b-1, c-1);
        return dp[a][b][c];
    }
}

int main(){
    ll a,b,c;
    ll number;
    while (true) {
        cin>>a>>b>>c;
        if (a == -1 && b==-1 && c==-1) break;
        number = comp(a,b,c);
        cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<number<<endl;
    }
    return 0;
}
