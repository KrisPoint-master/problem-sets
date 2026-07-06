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

    // 遍历点u 周围点
    template <typename U>
    void for_each(long long u, U func)
    {
        for (long long i = h[u]; i != -1; i = e[i].next)
            func(e[i].u, e[i].v, e[i].w); // u v w
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

long long n, m;
long long vis[maxn];
long long u, v;
typedef struct
{
    long long u;
    long long v;
} ed;
ed l[100005];
long long cmp(ed a, ed b)
{
    if (a.v == b.v)
        return a.u < b.u;
    return a.v > b.v;
}

void dfs(long long u)
{
    vis[u] = 1;
    cout << u << " ";
    for (long long i = e(u); i != -1; i = e[i].next)
    {
        long long v = e[i].v;
        if (!vis[v])
            dfs(v);
    }
}

void reinit()
{
    memset(vis, 0, sizeof(vis));
    cout << endl;
}

void bfs(long long u)
{
    queue<long long> q;
    q.push(u);
    vis[u] = 1;
    while (!q.empty())
    {
        long long f = q.front();
        q.pop();
        cout << f << " ";
        for (long long i = e(f); i != -1; i = e[i].next)
        {
            long long v = e[i].v;
            if (!vis[v])
            {
                q.push(v);
                vis[v] = 1;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (long long i = 1; i <= m; i++)
    {
        cin >> u >> v;
        l[i].u = u;
        l[i].v = v;
    }
    sort(l + 1, l + m + 1, cmp);
    for (long long i = 1; i <= m; i++)
    {
        // cout << u << " " << v << endl;
        e.add(l[i].u, l[i].v);
    }

    dfs(1);
    reinit();
    bfs(1);
    cout << endl;
    return 0;
}
