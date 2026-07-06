#include<bits/stdc++.h>
using namespace std;

int n,M,T; 
int m[100005],t[100005];

int main(int argc, char const *argv[])
{
    cin >> n >> M >> T;
    for (int i = 0; i < n; i++)
    {
        cin >> m[i] >> t[i];
    }
    sort(m,m+n);
    sort(t,t+n);
    int ans = 0;
    for(int i = 0;;i++){
        M -= m[i];
        T -= t[i];
        if(M <= 0 || T <= 0) break;
        ans ++;
    }
    cout << ans << endl;
    
    return 0;
}

