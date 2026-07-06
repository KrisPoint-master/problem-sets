#include <bits/stdc++.h>
using namespace std;

int n,m;
int v[10005],w[10005],j[10005];
int f[1005][1005];

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int i = 1; i < m; i++)
    {
        cin >> w[i] >> v[i] >> j[i];
        w[i] *= v[i];
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++){
            f[i][j] = f[i-1][j];
            
        }
        
    }
    
    
    return 0;
}
