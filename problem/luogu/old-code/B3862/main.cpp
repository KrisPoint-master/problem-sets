#include <bits/stdc++.h>
using namespace std;

const long long maxn = 1e6 + 5;
const long long maxe = 1e6 + 5;

struct linkList
{
    typedef struct
    {
        long long u, v, w, next;
    } edge;
    edge e[maxe];
    long long h[maxn], edge_cnt = 0;
    linkList()
    {
        edge_cnt = 0;
        memset(h, -1, sizeof(h));
    }
    void add(long long u, long long v, long long w = 0)
    {
        e[edge_cnt] = {u, v, w, h[u]};
        h[u] = edge_cnt++;
    }
    void add2(long long u, long long v, long long w = 0)
    {
        add(u, v, w);
        add(v, u, w);
    }
    // 下标访问
    edge &operator[](long long i) { return e[i]; }
    // 返回head[u]
    long long operator()(long long u) { return h[u]; }
} e;
bool vis[maxn];


long long ans = 0;
void dfs(long long u)
{
    vis[u] = true;
    if (u > ans) ans = u;
    for (long long i = e(u); i != -1; i = e[i].next)
    {
        long long t = e[i].v;
        if (!vis[t])
            dfs(t);
    }
    return;
}
int main()
{
    long long n, m;
    cin >> n >> m;
    for (long long i = 1; i <= m; i++)
    {
        long long u, v;
        cin >> u >> v;
        e.add(u, v);
    }

    for (long long i = 1; i <= n; i++)
    {
        ans = 0;
        memset(vis, 0, sizeof(vis));
        dfs(i);
        cout << ans << " ";
    }

    return 0;
}
