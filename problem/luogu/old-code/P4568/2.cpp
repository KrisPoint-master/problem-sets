#include <bits/stdc++.h>
using namespace std;

const int MAXN = 111111 + 5;
const int MAXE = 1111111 + 5;
const int INF = 0x3f3f3f3f;

struct LinkList
{
    struct Edge
    {
        int u, v, w, next;
    };
    Edge e[MAXE];
    int h[MAXN], edge_cnt = 0;

    LinkList()
    {
        edge_cnt = 0;
        memset(h, -1, sizeof(h));
    }

    template <typename Func>
    void forEach(int u, Func func)
    {
        for (int i = h[u]; ~i; i = e[i].next)
            func(e[i].v, e[i].w);
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

    Edge &operator[](int i) { return e[i]; }
    int operator()(int u) { return h[u]; }
} G;

int n, m, k, s, t;
int f[MAXN][21];

struct DijkstraWithKFree
{
    using Node = pair<int, int>;

    void work(int s)
    {
        for (int i = 0; i <= k; ++i)
            f[s][i] = 0;

        for (int used = 0; used <= k; ++used)
        {
            priority_queue<Node, vector<Node>, greater<Node>> q;
            q.push({0, s});

            while (!q.empty())
            {
                auto [curDist, u] = q.top();
                q.pop();

                if (curDist > f[u][used])
                    continue;

                G.forEach(u, [&](int v, int w)
                          {
                    bool updated = false;

                    // 免费使用一次边
                    if (used > 0 && f[v][used] > f[u][used - 1])
                    {
                        f[v][used] = f[u][used - 1];
                        updated = true;
                    }

                    // 普通转移
                    if (f[v][used] > f[u][used] + w)
                    {
                        f[v][used] = f[u][used] + w;
                        updated = true;
                    }

                    if (updated)
                        q.push({f[v][used], v}); });
            }
        }
    }
} solver;

int main()
{
    cin >> n >> m >> k >> s >> t;
    for (int i = 1; i <= m; ++i)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        G.add2(x, y, z);
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= k; ++j)
            f[i][j] = INF;

    solver.work(s);
    printf("%d\n", f[t][k]);

    return 0;
}
