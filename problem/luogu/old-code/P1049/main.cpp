#include <bits/stdc++.h>
using namespace std;

long long n,m,ans,f[1005][20005];
long long a[20005];
long long v;

int main(int argc, char const *argv[])
{
    cin >> v >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            f[i][j] = f[i-1][j];
            if(j >= a[i])
                f[i][j] = max(f[i][j],f[i-1][j-a[i]]+a[i]);
        }
    }
    #ifdef DEBUG
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= v; j++)
        {
            cout << f[i][j] << " ";
        }
        cout << endl;        
    }
    
    #endif
    cout << v-f[n][v] << endl;
    
    return 0;
}
