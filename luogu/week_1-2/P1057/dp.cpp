#include <bits/stdc++.h>
using namespace std;

int n, m;

#define START_POS 1
#define MAXN (30 + 5)
#define MAXM (30 + 5)

int next_pos(int np)
{
    return np == n ? 1 : np + 1;
}

int prev_pos(int np)
{
    int t = (np - 1);
    return (t == 0) ? n : t;
}

int f[MAXN][MAXM];
/*
int dfs(int dep, int np)
{
    if (f[dep][np] != -1)
        return f[dep][np];

    if (dep > m)
    {
        if (np == START_POS)
            return 1;
        return 0;
    }

    int t1 = dfs(dep + 1, prev_pos(np));
    int t2 = dfs(dep + 1, next_pos(np));

    return f[dep][np] = t1 + t2;
}
*/

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    // int ans = dfs(1, START_POS);
    // cout << ans << endl;

    // f(i,j) is (i -> now_pos; j -> now_m)
    // so f(i,j) = f(i-1,j-1) + f(i+1,j+1)

    f[1][0] = 1;
    for (int j = 1; j <= m; j++)
    {
        f[1][j] = f[2][j - 1] + f[n][j - 1];
        f[n][j] = f[1][j - 1] + f[n - 1][j - 1];
        for (int i = 2; i < n; i++)
            f[i][j] = f[i - 1][j - 1] + f[i + 1][j - 1];
    }
    cout << f[1][m] << endl;
    return 0;
}
