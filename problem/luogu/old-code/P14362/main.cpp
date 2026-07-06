#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long maxn = 1e7 + 5, maxe = 1e7 + 5; // 点与边的数量

long long n, m;
/* 定义全局变量 */

struct linkList
{
    typedef struct
    {
        long long u, v, w, next;
    } edge;
    edge e[maxe];
    long long h[maxn], edge_cnt = 0;
    linkList()
    { // 构造函数
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
    edge &operator[](long long i)
    {
        return e[i];
    }
    void sort()
    {
        std::sort(e, e + edge_cnt, [](edge &e1, edge &e2)
                  { return e1.w < e2.w; });
    }
} e;

template <long long size>
struct DisjointSet
{
    long long fa[size + 5];
    DisjointSet()
    {
        for (long long i = 0; i <= size + 4; ++i)
            fa[i] = i;
    }
    long long find(long long u)
    {
        if (u == fa[u])
            return u;
        return fa[u] = find(fa[u]);
    }
    inline void un(long long u, long long v)
    {
        fa[find(u)] = find(v);
    }
};

template <long long size = maxn>
struct Kruskal
{
    long long work(linkList &e)
    {
        e.sort();
        long long ans = 0, cnt = 0; // 答案，选边的数量
        for (long long i = 0; i < e.edge_cnt; i++)
        { // 遍历每条边
            long long u = e[i].u, v = e[i].v, w = e[i].w;
            long long f1 = joinSet.find(u), f2 = joinSet.find(v);
            if (f1 != f2)
            { // 不再同一个集合
                ans += w;
                cnt++;
                // std::cout << u << " " << v << " " << w << std::endl;
                joinSet.fa[f2] = f1;
            }
            if (cnt == n - 1)
                break;
        }
        if (cnt < n - 1)
            return -1; // 表明不可能形成一个生成树
        return ans;
    }
    DisjointSet<size> joinSet;
};
Kruskal<maxn> krus;

int main(long long argc, char *argv[])
{
    long long k;
    std::cin >> n;
    std::cin >> m;
    cin >> k;
    for (long long i = 1; i <= m; ++i)
    {
        long long u, v, w;
        std::cin >> u >> v >> w;
        e.add(u, v, w); // 只要加一次
    }

    // 建完图
    long long ans = krus.work(e);
    std::cout << ans;

    return 0;
}