#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;

int n,c;
int f[maxn][maxn];
int w[maxn]; 
int v[maxn]; 
int main(int argc, char const *argv[])
{
    cin >> c >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= c;  j++){
            f[i][j] = f[i-1][j];
            if(j - w[i] >=  0)
                f[i][j] = max(f[i][j],f[i-1][j-w[i]]+v[i]);
        }
    cout << f[n][c];    
    return 0;
}
