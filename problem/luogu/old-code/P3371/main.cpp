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

const int INF = 0x7f7f7f7f;
const long long NO_GET = 2147483647; // 2^31-1

int n, m, s;

struct dijkstra
{
    int dis[maxn], vis[maxn];
    using P = pair<int, int>;
    priority_queue<P, vector<P>, greater<P>> q;
    dijkstra()
    {
        memset(dis, 0x7f, sizeof(dis));
        memset(vis, 0, sizeof(vis));
    }

    void work_simple(int s)
    {
        dis[s] = 0;
        for (int i = 1; i <= n; i++)
        {
            int m = INF, u = -1;
            for (int j = 1; j <= n; j++)
            {
                if (vis[j] == 0 && m > dis[j])
                    u = j, m = dis[j];
            }
            if (u == -1)
                return;

            vis[u] = 1;

            for (int j = e(u); ~j; j = e[j].next)
            {
                int v = e[j].v;
                int w = e[j].w;
                if (vis[v] == 0 && dis[v] > dis[u] + w)
                    dis[v] = dis[u] + w;
            }
        }
    }

    void work_heap(int s)
    {
        dis[s] = 0;
        q.push(make_pair(0, s));

        while (!q.empty())
        {
            int u = q.top().f2;
            q.pop();
            if (vis[u])
                continue;
            vis[u] = 1;

            for (int i = e(u); ~i; i = e[i].next)
            {
                int v = e[i].v;
                int w = e[i].w;
                if (vis[v] == 0 && dis[v] > dis[u] + w)
                    dis[v] = dis[u] + w, q.push(make_pair(dis[v], v));
            }
        }
    }

} dijkstra;

int main(int argc, char const *argv[])
{
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        e.add(u, v, w);
    }

    dijkstra.work_heap(s);

    for (int i = 1; i <= n; i++)
    {
        cout << ((dijkstra.dis[i] != INF) ? dijkstra.dis[i] : NO_GET) << " ";
    }

    return 0;
}
