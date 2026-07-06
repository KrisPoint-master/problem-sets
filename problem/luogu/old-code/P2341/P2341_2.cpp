#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5;
const int maxe = 1e6+5;

struct linkList {
    typedef struct {int u,v,w,next;} edge;
    edge e[maxe];
    int h[maxn],edge_cnt=0;
    linkList(){
        edge_cnt=0;
        memset(h,-1,sizeof(h));
    }

    //遍历点u 周围点
    template<typename U>
    void for_each(int u,U func){
        for(int i = h[u] ; i !=-1;i = e[i].next)
            func(e[i].u,e[i].v,e[i].w); //u v w
    }

    void add(int u,int v,int w=0){
        e[edge_cnt] = {u,v,w,h[u]};
        h[u] = edge_cnt++;
    }
    void add2(int u,int v,int w=0){
        add(u,v,w);
        add(v,u,w);
    }
    //下标访问
    edge& operator[](int i){ return e[i]; }
    //返回head[u]
    int operator()(int u){ return h[u]; }
} e,e2;
stack<int> sta; //栈

int n,m;
int vis[maxn];
int dfn[maxn];
int low[maxn];
int color[maxn];
bool issta[maxn];
int color_cnt;
int t;

void dfsscc(int u){
    vis[u] = 1;
    dfn[u] = low[u] = ++t;
    sta.push(u);
    issta[u] = 1;
    for (int i = e(u); i != -1; i = e[i].next)
    {
        int v = e[i].v;
        if (vis[v] == 0)
        {
            dfsscc(v);
            low[u] = min(low[u],low[v]);
        }
        else if (issta[v])
        {
            low[u] = min(low[u],dfn[v]);
        }
    }
    if (dfn[u] == low[u])
    {
        color_cnt++;
        int ti = 0;
        do{
            ti = sta.top();
            sta.pop();
            issta[ti] = 0;
            color[ti] = color_cnt;
        }while(ti != u);
    }
}
int sd_point_n;
void sd(int u)
{
    vis[u] = 1;

    for (int i = e(u); i != -1; i = e[i].next)
    {
        int v = e[i].v;
        if(!vis[v])
        {
            if(color[u] != color[v]){
                e2.add(color[u],color[v]);
                sd_point_n++;
            }
            sd(v);
        }
    }
}

queue<int> que;
// find DAG outdeg is 0 point
void dfs_find_outdeg0(int u)
{
    vis[u] = 1;
    int cnt = 0;
    for (int i = e2(u); i != -1; i = e2[i].next)
    {
        cnt++;
        if(!vis[e2[i].v])
        {
            dfs_find_outdeg0(e2[i].v);
        }
    }
    if(cnt == 0)
    {
        que.push(u);
    }
}

int main () {
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int u,v;
        cin >> u >> v;
        e.add(u,v);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i]) dfsscc(1); 
    }
    memset(vis,0,sizeof(vis));
    sd(1);
    memset(vis,0,sizeof(vis));
    for (int i = 1; i <= sd_point_n; i++)
    {
        dfs_find_outdeg0(i);
    }
    
    if (que.size() != 1)
    {
        cout << 0 << endl;
        return 0;
    }
    
    int find_deg0 = que.front();
    // color
    int pcnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if(find_deg0 == color[i])
        {
            pcnt ++;
        }
    }
    cout << pcnt << endl;

    return 0;
}
