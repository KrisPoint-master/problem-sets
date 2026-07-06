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
} win, lose;

int n, m;
int vis[maxn];
int win_cnt;
int lost_cnt;

void calc_win(int u)
{
    win_cnt ++;
    vis[u] = 1;
    for (int i = win(u); i != -1; i = win[i].next)
    {
        int v = win[i].v;
        if(!vis[v])
        {
            calc_win(v);
        }
    }
}

void calc_lose(int u)
{
    lost_cnt ++;
    vis[u] = 1;
    for (int i = lose(u); i != -1; i = lose[i].next)
    {
        int v = lose[i].v;
        if(!vis[v])
        {
            calc_lose(v);
        }
    }
}

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        win.add(u,v);
        lose.add(v,u);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        win_cnt = lost_cnt = -1;
        calc_win(i);
        memset(vis,0,sizeof(vis));
        calc_lose(i);
        memset(vis,0,sizeof(vis));
        if(win_cnt + lost_cnt == n-1)
        {
            ans ++;
        }
    }
    cout << ans << endl;
    

    return 0;
}