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

bool vis[maxn];
int u,v,t,nol;
int su,sv;
int ans;

void dfs(int u){
    vis[u] = 1;
    // cout << u << " ";
    if(u == sv) t = 1;
    if(u == nol) return;
    for(int i = e(u);i!=-1;i = e.e[i].next){
        int l = e.e[i].v;
        if(!vis[l] && l != nol)
            dfs(l);
    }
}

int main(int argc, char const *argv[])
{
    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        e.add2(u,v);
    }
    cin >> su >> sv;

    for (int i = 1; i <= n; i++)
    {
        if(i == su || i == sv) continue;
        nol = i;
        t = 0;
        memset(vis,0,sizeof(vis));
        vis[nol] = 1;
        dfs(su);
        // cout << "       " << t << endl;
        ans += !t;
    }
    cout << ans << endl;
    
    return 0;
}
