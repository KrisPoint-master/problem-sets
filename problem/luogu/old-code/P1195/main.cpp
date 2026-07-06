#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
const int maxm = 1e6;
struct linkList
{
    typedef struct
    {
        int u, v, w, next;
    } edge;
    edge e[maxm];
    int h[maxn], edge_cnt = 0;
    linkList()
    { // 构造函数
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

int n, m, k, cnt;
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
int kruskal() // MST Kruskal (easy) no Prim
{
    int res = 0, nft = n;
    DisjointSet<maxn> dis;
    e.sort();
    for (int i = 1; i <= m; i++)
    {
        if (nft <= k)
            break;
        int fu = dis.find(e[i].u);
        int fv = dis.find(e[i].v);
        if (fu != fv)
        {
            dis.un(fu, fv);
            res += e[i].w;
            nft--;
        }
    }
    if (nft == k)
        return res;
    return -1;
}
int main()
{
    int u, v, w, ans;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        e.add2(u, v, w);
    }
    ans = kruskal();
    if (ans == -1)
        cout << "No Answer" << endl;
    else
        cout << ans << endl;

    return 0;
}