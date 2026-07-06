#include <bits/stdc++.h>
using namespace std;
const int maxn = 30005;
int n, m;
int l;
int v[maxn];
int w[maxn];
int f[30][maxn];

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> w[i];
        cin >> v[i];
        v[i] *= w[i];
        // cout << " Vi " << v[i] << endl; 
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = f[i - 1][j];
            if (j >= w[i])
            {
                if((f[i][j]) < (f[i-1][j-w[i]] + v[i])){
                    f[i][j] = (f[i-1][j-w[i]] + v[i]);
                }
            }
            // cout << f[i][j] << "  ";
        }
        // cout << endl;
    }
    // cout << endl;
    cout << f[m][n];
    // cout << endl;
    return 0;
}
