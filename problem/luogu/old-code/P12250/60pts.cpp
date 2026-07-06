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

int n, m;

int reach_all_vis[maxn];
void reach_all(int u)
{
    reach_all_vis[u] = 1;
    for (int i = e(u); i != -1; i = e[i].next)
    {
        int v = e[i].v, w = e[i].w;
        if (!reach_all_vis[v])
        {
            reach_all(v);
        }
    }
}
int vis_all0[maxn];
void reach_target_1(int u)
{
    vis_all0[u] = 1;
    for (int i = e(u); i != -1; i = e[i].next)
    {
        int v = e[i].v, w = e[i].w;
        if (!vis_all0[v] && w == 0)
        {
            reach_target_1(v);
        }
    }
}
int vis_all10[maxn];
void reach_vis_10(int u)
{
    vis_all10[u] = 1;
    for (int i = e(u); i != -1; i = e[i].next)
    {
        int v = e[i].v, w = e[i].w;
        if (!vis_all10[v])
        {
            reach_target_1(v);
        }
    }
}

int main()
{
    long long total_ans = 0;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int p, q, r;
        cin >> p >> q >> r;
        e.add(p, q, r);
    }
    for (int s = 1; s <= n; s++)
    {
        memset(reach_all_vis, 0, sizeof(reach_all_vis));
        memset(vis_all0, 0, sizeof(vis_all0));
        memset(vis_all10, 0, sizeof(vis_all10));
        reach_all(s);
        reach_target_1(s);
        for (int u = 1; u <= n; u++)
        {
            if (vis_all0[u])
            {
                for (int i = e(u); i != -1; i = e[i].next)
                {
                    if (e[i].w == 1 && !vis_all10[i])
                    {
                        reach_vis_10(i);
                    }
                }
            }
        }
        for (int t = 1; t <= n; ++t)
        {
            if (s == t)
                continue;

            if (!reach_all_vis[t])
                total_ans -= 1; // Case 1: 根本走不到
            else if (vis_all0[t])
                total_ans += 2; // Case 2: 路径能凑齐 {0, 1}
            else if (vis_all10[t])
                total_ans += 1; // Case 3: 路径能凑齐 {0}
        }
    }
    cout << total_ans << endl;

    return 0;
}