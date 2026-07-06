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
    edge edges[maxe]; // 修改：避免与全局变量名冲突
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
        for (int i = h[u]; i != -1; i = edges[i].next)
            func(edges[i].u, edges[i].v, edges[i].w);
    }

    void add(int u, int v, int w = 0)
    {
        edges[edge_cnt] = {u, v, w, h[u]};
        h[u] = edge_cnt++;
    }
    void add2(int u, int v, int w = 0)
    {
        add(u, v, w);
        add(v, u, w);
    }
    // 下标访问
    edge &operator[](int i) { return edges[i]; }
    // 返回head[u]
    int operator()(int u) { return h[u]; }
} e; // 修改：将全局变量 e 改为 G，避免命名冲突

struct cir
{
    int u;
    int w;
} circle[maxn];
int top = 0;

int vis[maxn];

int dfs(int u, int fa)
{
    if (vis[u] == 1)
        return u;
    if (vis[u] == 2)
        return 0;

    vis[u] = 1;
    for (int i = e(u); i != -1; i = e[i].next)
    {
        int v = e[i].v;
        if (v == fa)
            continue;
        int t = dfs(v, u);
        if (t != 0)
        {
            circle[++top].u = u;
            circle[top].w = e[i].w;
            vis[u] = 2;
            if (t == u)
                return 0;
            return t;
        }
    }
    vis[u] = 2;
    return 0;
}

int main(int argc, const char **argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n))
        return 0;
    for (int i = 1; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        e.add2(u, v);
    }

    dfs(1, 0);

    auto cmp = [](cir a, cir b)
    {
        return a.u < b.u;
    };

    sort(circle + 1, circle + 1 + top, cmp);

    for (int i = 1; i <= top; i++)
    {
        cout << circle[i].u << (i == top ? "" : " ");
    }
    cout << "\n";

    return 0;
}