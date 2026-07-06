#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
        for (int i = 1; i <= e.edge_cnt; i++)
        {
            int u = e[i].u, v = e[i].v, w = e[i].w;
            int f1 = joinSet.find(u), f2 = joinSet.find(v);
            if (f1 != f2)
            {
                joinSet.un(f1, f2);
                ans += w;
            }
        }
        return ans;
    }
    DisjointSet<size> joinSet;
};
Kruskal<maxn> krus;
const int max_p = 1e3 + 5;
int w[maxn], p[max_p][max_p];
int main(int argc, char *argv[])
{
    DisjointSet<maxn> dis;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> p[i][j];
            if (i != j)
                e.add(i, j, p[i][j]);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        e.add(i, n + 1, w[i]);
        e.add(n + 1, i, w[i]);
    }

    int ans = krus.work(e);
    std::cout << ans;

    return 0;
}