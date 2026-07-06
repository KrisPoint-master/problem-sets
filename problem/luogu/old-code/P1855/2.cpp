#include<bits/stdc++.h>
using namespace std;

int n,m,t;
int M[1005],T[1005];
int f[203][203][203];
int main(int argc, char const *argv[])
{
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> M[i] >> T[i];
    }
    
    for(int i = 1;i <= n;i++){             // 枚举前i个
        for (int j = 1; j <= m; j++){      // 枚举MONEY
            for (int k = 1; k <= t; k++){  // 枚举TIME
                f[i][j][k] = f[i-1][j][k];
                if(j - M[i] >= 0 && k - T[i] >= 0){
                    f[i][j][k] = max(
                        f[i][j][k],
                        f[i-1][j-M[i]][k-T[i]]+1
                    );
                }
            }
        }
    }

    cout << f[n][m][t];

    return 0;
}
