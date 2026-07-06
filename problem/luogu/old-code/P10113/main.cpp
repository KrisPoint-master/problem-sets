#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 10;
int n, q, m, head[maxn], idx, dep[maxn], fa[maxn][25], ans;
struct edge
{
    int to;
    int nxt;
} e[maxn * 2];
void add2(int u, int v)
{
    e[++idx] = {v, head[u]};
    head[u] = idx;
}
void dfs(int u, int f)
{
    dep[u] = dep[f] + 1;
    for (int i = 1; i <= 20; ++i)
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].to;
        if (v != f)
            dfs(v, u);
    }
}
int lca(int a, int b)
{
    if (dep[a] < dep[b])
        swap(a, b);
    for (int i = 20; i >= 0; --i)
        if (dep[fa[a][i]] >= dep[b])
            a = fa[a][i];
    if (a == b)
        return a;
    for (int i = 20; i >= 0; --i)
        if (fa[a][i] != fa[b][i])
        {
            a = fa[a][i];
            b = fa[b][i];
        }
    return fa[a][0];
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; ++i)
    {
        cin >> fa[i][0];
        add2(fa[i][0], i);
        add2(i, fa[i][0]);
    }
    dfs(0, 0);
    cin >> q;
    while (q--)
    {
        int p, p1;
        cin >> m >> p;
        for (int i = 2; i <= m; ++i)
        {
            cin >> p1;
            p = lca(p, p1);
        }
        ans = p;
        while (p)
        {
            ans = max(ans, fa[p][0]);
            p = fa[p][0];
        }
        cout << ans << endl;
    }
    return 0;
}