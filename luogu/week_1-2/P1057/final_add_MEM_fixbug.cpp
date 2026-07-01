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

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    memset(f, -1, sizeof(f));
    int ans = dfs(1, START_POS);
    cout << ans << endl;
    return 0;
}