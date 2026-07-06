#include <bits/stdc++.h>
using namespace std;

const int maxn = 10005;

int n, mp[100][100],a[maxn];
int f[maxn];
int rcd[maxn];
int start;
int main(int argc, char const *argv[])
{
    cin >> n;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n - 1; i++)
    {
        for(int j = i+1;j<=n;j++){
            cin >> mp[i][j];
        }
    }

    for(int i = 1;i<=n;i++){
        f[i] = a[i];
    }

    for(int i = n;i>=1;i--){
        for(int j = i+1;j<=n;j++){
            if(mp[i][j] == 1){
                if(f[i] < f[j] + a[i]){
                    f[i] = f[j] + a[i];
                    rcd[i] = j;
                }
                //f[i] = max(f[i],f[j] + a[i]);
            }   
        }
    }
    int ans = INT16_MIN;
    for(int i = 1;i<=n;i++){
        if(ans < f[i]){
            ans = f[i];
            start = i;
        }
    }
    int t = start;
    while(t != 0){
        cout << t << " ";
        t = rcd[t];
    }
    cout << endl;
    cout << ans << endl;
    return 0;
}