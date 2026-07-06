#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e6+7;
const int maxn = 1e6+5;
int n,m,ans;
int a[maxn];
int f[10005][1005]; //桶

int main () {
    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i+1];
    }
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        f[i][0] = 1;
        for (int j = 1; j <= m; j++)
        {
            for (int k = 0; k <= min(a[i],j); k++)
            {
                f[i][j] += f[i-1][j-k];
                f[i][j] %= MOD;
            }
        }
    }
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= m; j++)
    //     {
    //         cout << f[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    cout << f[n][m] << endl;
    return 0;
}

