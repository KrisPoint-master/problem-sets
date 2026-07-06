#include<bits/stdc++.h>
using namespace std;

int t,n,m;
int f[10000005];
int p[1005][1005];

int main(int argc, char const *argv[])
{
    memset(f,0,sizeof(f));
    cin >> n >> t >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= t; j++)
        {
            cin >> p[j][i];
        }
    }
    int s = 0;
    for (int day = 1; day <= t; day++)
    {
        memset(f,0,sizeof(f));
        for (int i = 1; i <= n; i++)
            for (int j = p[day][i]; j <= m; j++)
                f[j] = max(f[j],f[j-p[day][i]] + p[day + 1][i] - p[day][i]);
        m = max(f[m] + m,m);
    }
    cout << m << endl;
    return 0;
}
