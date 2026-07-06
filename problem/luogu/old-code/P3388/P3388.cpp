#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e7+5;
const int maxe = 1e7+5;

int n,m;
bool vis[maxn];
bool iscut[maxn];
int dfn[maxn];
int low[maxn];
int dfs_time; 

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
} e;

void tarjan_cut(int u,int fa) {
    int child = 0;
    dfn[u] = low[u] = ++dfs_time;
    vis[u] = 1; 
    for(int i = e(u);i != -1;i = e[i].next) {
        int v = e[i].v;
        if( v == fa) continue;
        if( vis[v] == false)  {
            child++;
            tarjan_cut(v,u);
            low[u] = min(low[u],low[v]);
            if( fa != 0  &&  low[v] >= dfn[u]) 
                iscut[u] = 1;
        }
        else {
            low[u] = min(low[u],dfn[v]);
        }
    }
    
    if( fa == 0 && child >= 2)
        iscut[u] = 1;
}


int main () {
    cin >> n >> m;
    for(int i =1;i<=m;i++) {
        int u,v;
        cin >> u >> v;
        e.add2(u,v);
    }
    for (int i = 1; i <= n; i++)
    {
        if(vis[i] == 0)
            tarjan_cut(i,0);
    }
    
    int cnt = 0;
    for(int i = 1;i <= n;i++) {
        if(iscut[i])
            cnt++;
    }
    cout << cnt << endl;
    for (int i = 1; i <= n; i++)
    {
        if(iscut[i])
        {
            cout << i << " ";
        }
    }
    
    return 0;
}
