#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll INF=0x7fffffff;
ll fp[10000002];
ll m;
ll f(ll i)
{
    if(fp[i])return fp[i];
    if(i==1||i==2)return fp[i]=1%m;
    else return fp[i]=(f(i-1)+f(i-2))%m;
}
int main()
{
    cin >> m;
    ll i=1;
    while(f(i)!=0||f(i+1)!=1)
    {
        i++;
    }
    cout << i << endl;
    return 0;
}