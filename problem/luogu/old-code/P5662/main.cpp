#include<bits/stdc++.h>
using namespace std;

int t,n,m;
int f[100005];
int p[1005][10005];

int main(int argc, char const *argv[])
{
    cin >> t >> n >> m;
    for (int i = 1; i <= t; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> p[i][j];
        }
    }
    if(t == 1){ cout << m;return 0;}
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
