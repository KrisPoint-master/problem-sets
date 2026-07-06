#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5, maxe = 1e6 + 5;
int n, m;
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
    edge &operator[](int i)
    {
        return e[i];
    }
    void sort()
    {
        std::sort(e, e + edge_cnt, [](edge &e1, edge &e2)
                  { return e1.w < e2.w; });
    }
} e;

template <int size>
struct DisjointSet
{
    int fa[size + 5];
    DisjointSet()
    {
        for (int i = 0; i <= size + 4; ++i)
            fa[i] = i;
    }
    int find(int u)
    {
        if (u == fa[u])
            return u;
        return fa[u] = find(fa[u]);
    }
    inline void un(int u, int v)
    {
        fa[find(u)] = find(v);
    }
};

template <int size = maxn>
struct Kruskal
{
    int work(linkList &e)
    {
        e.sort();
        int ans = 0, cnt = 0;
        for (int i = 0; i < e.edge_cnt; i++)
        {
            int u = e[i].u, v = e[i].v, w = e[i].w;
            int f1 = joinSet.find(u), f2 = joinSet.find(v);
            if (f1 != f2)
            {
                ans += w;
                cnt++;
                // std::cout << u << " " << v << " " << w << std::endl;
                joinSet.fa[f2] = f1;
            }
            if (cnt == n - 1)
                break;
        }
        if (cnt < n - 1)
            return -1;
        return ans;
    }
    DisjointSet<size> joinSet;
};
Kruskal<maxn> krus;

int main(int argc, char *argv[])
{
    cin >> n;
    cin >> m;
    for (int i = 1; i <= m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e.add(u, v, w);
    }
    int ans = krus.work(e);
    if (ans == -1)
    {
        cout << "orz" << endl;
        return 0;
    }
    cout << ans << endl;

    return 0;
}