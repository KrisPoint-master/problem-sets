#include <bits/stdc++.h>
using namespace std;
int n,m;
int g[155][5005];
int vis[100005];
int cnt;

typedef struct {int u,v;} uv;
uv delp;
/*
枚举一条边，将这条边去掉后随便选一个点进行DFS遍历，看是否能遍历到所有的点。
*/
void dfs(int u)
{
    cnt++;
    vis[u] = 1;
    for (int i = 1;i <= n;i++)
    {
        if(!g[u][i] || !g[i][u]) continue;
        if(!vis[i])
        {
            dfs(i);
        }
    }
}

uv ans[100005];
int push_ele = 0;

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u,v;
        cin >> u >> v;
        g[u][v] = g[v][u] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(g[i][j] == 0 || g[j][i] == 0) continue;
            g[i][j] = g[j][i] = 0;
            memset(vis,0,sizeof(vis));
            dfs(1);
            g[i][j] = g[j][i] = 1;
            if(n != cnt)
            {
                ans[++push_ele] = {i,j};
            }
            cnt = 0;
        }
    }
    
    for (int i = 1; i <= push_ele; i++)
    {
        if(ans[i].u < ans[i].v)
            cout << ans[i].u << " " << ans[i].v << endl;
    }
    
    
    return 0;
}
