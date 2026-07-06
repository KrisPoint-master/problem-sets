#include <bits/stdc++.h>
using namespace std;
const int maxn = 500050;
int n, m, q, x, y, head[maxn << 1], tot, dep[maxn], f[maxn][21];
struct node
{
    int to, nxt;
} e[maxn << 1];
inline void add(int u, int v)
{
    e[++tot].to = v;
    e[tot].nxt = head[u];
    head[u] = tot;
}
inline void dfs(int u, int pre)
{
    dep[u] = dep[pre] + 1;
    f[u][0] = pre;
    for (int i = 1; i <= 20; i++)
        f[u][i] = f[f[u][i - 1]][i - 1];
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].to;
        if (v != pre)
        {
            f[v][0] = u;
            dfs(v, u);
        }
    }
}
inline int lca(int x, int y)
{
    if (dep[x] < dep[y])
        swap(x, y);
    for (int i = 20; i >= 0; i--)
    {
        if (dep[f[x][i]] >= dep[y])
            x = f[x][i];
        if (x == y)
            return x;
    }
    for (int i = 20; i >= 0; i--)
        if (f[x][i] != f[y][i])
            x = f[x][i], y = f[y][i];
    return f[x][0];
}
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

int ask[maxn];
int forans[maxn];
int main()
{
    // n = read();
    // q = read();
    // m = read();
    // for (int i = 1; i < n; i++)
    // {
    //     x = read();
    //     y = read();
    //     add(x, y);
    //     add(y, x);
    // }
    // dfs(m, 0);
    // while (q--)
    // {
    //     x = read();
    //     y = read();
    //     printf("%d\n", lca(x, y));
    // }
    n = read(), m = read(), q = read();
    for (int i = 1; i < n; i++)
    {
        x = read(), y = read();
        add(x, y);
        add(y, x);
    }
    dfs(m, 0);

    for (int i = 1; i <= m; i++)
    {
        ask[i] = read();
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            int s = lca(i, j);
            forans[s]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (forans[i])
            forans[i]++;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << forans[i] << endl;
    }

    return 0;
}