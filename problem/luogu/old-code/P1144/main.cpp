#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e6 + 5;
const int maxe = 3e6 + 5;

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
int f[maxn];

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
            int u = q.top().second;
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
int k, t;

queue<int> q; // bfs
int b[maxn];  // buk
int vis[maxn];

const int mod = 100003;

void bfs(int s, int t = n)
{
    q.push(s);
    vis[s] = 1;
    f[1] = 1;
    while (!q.empty())
    {
        int fr = q.front();
        q.pop();
        for (int i = e(fr); i != -1; i = e[i].next)
        {
            int v = e[i].v;
            if (vis[v] && dijkstra.dis[v] == (dijkstra.dis[fr] + 1))
            {
                f[v] += f[fr] % mod;
                f[v] %= mod;
            }
            if (!vis[v])
            {
                f[v] = f[fr];

                q.push(v);
                vis[v] = 1;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    // cin >> s >> t;
    int s = 1;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        e.add2(u, v, 1);
    }

    dijkstra.work_heap(s);
    bfs(1);

    for (int i = 1; i <= n; i++)
    {
        cout << f[i] % mod << endl;
        // #ifndef ONLINE_OJ
        //         cout << " " << dijkstra.dis[i] << endl;
        // #endif //
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << ((dijkstra.dis[i] != INF) ? dijkstra.dis[i] : NO_GET) << " ";
    // }

    return 0;
}
