#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
int a[maxn];
int i,n,ans;


int main(){
    cin >> n;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
        a[i] += a[i-1];
    }
    for(int i = 1;i<=n;i++){
        for(int j = i + ans;j<=n;j++){
            if((a[j] - a[i-1]) % 7 == 0)
                ans = j - i + 1;
        }
    }
    cout << ans;
    return 0;
}

