#include<bits/stdc++.h>
using namespace std;

int n,m;
int w[1005];
int f[1005][10005];

int main(int argc, char const *argv[])
{
    memset(f,0,sizeof(f));
    f[0][0] = 1;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m;j++)
        {
            f[i][j] = f[i-1][j];
            if(j < w[i] || f[i-1][j-w[i]] == 0){ 
                continue;
            }
            f[i][j] += f[i-1][j-w[i]];
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
