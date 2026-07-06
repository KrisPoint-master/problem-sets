#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
const int maxe = 2e5 + 5;

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

    template <typename U>
    void for_each(int u, U func)
    {
        for (int i = h[u]; i != -1; i = e[i].next)
            func(e[i].u, e[i].v, e[i].w);
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

    edge &operator[](int i) { return e[i]; }
    int operator()(int u) { return h[u]; }

} g;

int n;
int indeg[maxn];
bool r[maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int p;
        cin >> p;
        g.add(i, p);
        indeg[p]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indeg[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        r[u] = true;

        int v = g[g(u)].v;
        indeg[v]--;
        if (indeg[v] == 0)
            q.push(v);
    }

    int ans = 1e9;

    for (int i = 1; i <= n; i++)
    {
        if (!r[i])
        {
            int cnt = 0;
            int u = i;
            while (!r[u])
            {
                r[u] = true;
                cnt++;
                u = g[g(u)].v;
            }
            ans = min(ans, cnt);
        }
    }

    cout << ans << '\n';
    return 0;
}