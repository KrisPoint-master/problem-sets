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

long long sum = 0;
vector<int> temp_arr;
vector<int> back_history;
int vis[maxn];
long long max_d = -1; // 存储 d(s, t)
void dfs(int s, int t, int u, int cut_or)
{
    vis[u] = 1;
    // cout << u << " ";
    // s : start
    // t : end
    // u : now
    if (s == t)
        return;
    if (s > t)
    {
        sum -= 1;
        return;
    }

    if (u == t)
    {
        sort(back_history.begin(), back_history.end());
        // int m = mex(back_history);
        int m = 0;
        for (int val : back_history)
        {
            if (val == m)
                m++;
            else if (val > m)
                break;
        }
        max_d = max(max_d, (long long)m);
        // 两座城市 s,t 之间的距离为从s走到 t所有可能的游览方案中疲劳度的最大值
    }
    for (int i = e(u); i != -1; i = e[i].next)
    {
        int v = e[i].v;
        if (!vis[v])
        {
            long long now_or = cut_or | e[i].w;
            back_history.push_back(now_or);
            dfs(s, t, v, now_or);
            back_history.pop_back();
        }
    }
}

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int p, q, w;
        cin >> p >> q >> w;
        e.add(p, q, w);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            memset(vis, 0, sizeof(vis));
            dfs(i, j, i, 0);
        }
    }

    return 0;
}
