#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
const int maxe = 1e6 + 5;

struct linkList
{
    typedef struct
    {
        int u, v, w, next;
    } edge;
    edge e[maxe];
    int h[maxn], edge_cnt = 0;
    linkList()
    {
        edge_cnt = 0;
        memset(h, -1, sizeof(h));
    }

    // 遍历点u 周围点
    template <typename U>
    void for_each(int u, U func)
    {
        for (int i = h[u]; i != -1; i = e[i].next)
            func(e[i].u, e[i].v, e[i].w); // u v w
    }

    void add(int u, int v, int w = 0)
    {
        e[edge_cnt] = {u, v, w, h[u]};
        h[u] = edge_cnt++;
    }
    void add2(int u, int v, int w = 0)
    {
        add(u, v, w);
        add(v, u, w);
    }
    // 下标访问
    edge &operator[](int i) { return e[i]; }
    // 返回head[u]
    int operator()(int u) { return h[u]; }
} e;

int dis[maxn], vis[maxn];
int d, cnt;
int disu, disv;
void tree_dfs_mindistance(int u, int dis)
{
    vis[u] = 1;
    if (dis > d)
    {
        d = dis;
        disu = u;
    }
    for (int i = e(u); i != -1; i = e[i].next)
    {
        int v = e[i].v;
        if (!vis[v])
        {
            tree_dfs_mindistance(v, dis + 1);
        }
    }
}

int n, m;
int main(int argc, char const *argv[])
{
    cin >> n;
    m = n - 1;
    int u, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        e.add2(u, v);
    }

    tree_dfs_mindistance(1, 0);
    int x = disu;
    d = 0;
    memset(vis, 0, sizeof(vis));
    tree_dfs_mindistance(x, 0);
    cout << d << endl;

    return 0;
}
