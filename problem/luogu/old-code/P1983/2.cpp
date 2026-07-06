#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;    // 车站数
const int maxe = 1000005; // 边数最大约 10^6

struct linkList
{
    struct edge
    {
        int v, next;
    };
    edge e[maxe];
    int h[maxn], edge_cnt = 0;
    linkList()
    {
        edge_cnt = 0;
        memset(h, -1, sizeof(h));
    }
    void add(int u, int v)
    {
        e[edge_cnt] = {v, h[u]};
        h[u] = edge_cnt++;
    }
} e;

int n, m;
int in_deg[maxn];
int stops[maxn];
bool is_stop[maxn];
bool has_edge[maxn][maxn];
int dis[maxn];

void topsort()
{
    queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        if (in_deg[i] == 0)
        {
            q.push(i);
            dis[i] = 1;
        }
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int i = e.h[u]; ~i; i = e.e[i].next)
        {
            int v = e.e[i].v;
            dis[v] = max(dis[v], dis[u] + 1);
            if (--in_deg[v] == 0)
                q.push(v);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int k;
        cin >> k;
        memset(is_stop, 0, sizeof(is_stop));
        for (int j = 1; j <= k; j++)
        {
            cin >> stops[j];
            is_stop[stops[j]] = true;
        }

        for (int p = stops[1]; p <= stops[k]; p++)
        {
            if (!is_stop[p])
            {
                for (int j = 1; j <= k; j++)
                {
                    if (!has_edge[p][stops[j]])
                    {
                        e.add(p, stops[j]);
                        in_deg[stops[j]]++;
                        has_edge[p][stops[j]] = true;
                    }
                }
            }
        }
    }

    topsort();

    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, dis[i]);
    cout << ans << endl;

    return 0;
}