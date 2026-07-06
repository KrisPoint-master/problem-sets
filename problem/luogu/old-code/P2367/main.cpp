#include<bits/stdc++.h>
using namespace std;

int n,q;
int a[1e6+5];
int b[1e6+5];

int main(){
    cin >> n >> p;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        b[i] = a[i] - a[i-1];
    }
    for(int i = 1;i <= q;i++){
        int l,r,v;
        cin >> l >> r >> v;
        b[l] += v;
        b[r+1] -= v;
    }

    int sum = 0;
    int ans = 1145141919;
    for(int i = 1;i <= n;i++){
        sum += b[i];
        if(ans > sum)
            ans = sum;
    }
    cout << ans;
    return 0;
}
