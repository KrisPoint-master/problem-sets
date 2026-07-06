#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
using i64 = long long;
const int maxn = 5'000;
const int maxm = 10'000;
struct edge
{
    int v, w, next;
} e[maxm + 5];
int head[maxn + 5], tot[maxn + 5], vis[maxn + 5], cnt, n, m;
i64 dis[maxn + 5];
void addedge(int u, int v, int w)
{
    e[++cnt].v = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt;
}
bool spfa(int s)
{
    queue<int> q;
    memset(dis, 63, sizeof(dis));
    dis[s] = 0, vis[s] = 1;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].v;
            if (dis[v] > dis[u] + e[i].w)
            {
                dis[v] = dis[u] + e[i].w;
                if (!vis[v])
                {
                    vis[v] = 1, tot[v]++;
                    if (tot[v] == n + 1)
                        return false; // 注意添加了一个超级源点
                    q.push(v);
                }
            }
        }
    }
    return true;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        addedge(0, i, 0);
    for (int i = 1; i <= m; i++)
    {
        int v, u, w;
        cin >> v >> u >> w;
        addedge(u, v, w);
    }
    if (!spfa(0))
        cout << "NO" << endl;
    else
        for (int i = 1; i <= n; i++)
            cout << dis[i] << ' ';
    return 0;
}
