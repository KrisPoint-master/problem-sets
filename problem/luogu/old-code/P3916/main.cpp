#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
const int maxe = 1e5 + 5;

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
    void add(int u, int v, int w = 0)
    {
        e[edge_cnt] = {u, v, w, h[u]};
        h[u] = edge_cnt++;
    }
} e;

bool vis[maxn];
int ans[maxn];
int p;
void dfs(int u)
{
    vis[u] = 1;
    ans[u] = p;
    for (int i = e.h[u]; i != -1; i = e.e[i].next)
    {
        int v = e.e[i].v;
        if (!vis[v])
            dfs(v);
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        e.add(v,u);
    }

    for (int i = n; i >= 1; i--)
    {
        p = i;
        if(!vis[i]) dfs(i);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    

    return 0;
}
