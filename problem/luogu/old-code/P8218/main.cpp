#include<bits/stdc++.h>
using namespace std;

int n,m,l,r,t;
int a[1e5+5];

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> t;
        a[i] = t + a[i-1];
    }
    cin >> m;
    for(int i = 1;i <= m;i++){
        cin >> l >> r;
        cout << a[r] - a[l-1] << endl;
    }
    return 0;
}
