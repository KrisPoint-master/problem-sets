#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6+5;
const int maxe = 1e6+5;

// 强联通分量 ??????? Chapter 7

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

int n,m;
int vis[maxn];
int p;

void dfs(int u)
{
    vis[u] = 1;
    
    for (int i = e(u); i != -1; i = e[i].next)
    {
        int v = e[i].v;
        if (!vis[v])
        {
            dfs(v);
        }
    }
}

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        e.add(i,i);
        int u,v;
        cin >> u >> v;
        e.add(v,n);
    }
    int ans = 0;
    for (int i = n; i >= 1; i--)
    {
        memset(vis,0,sizeof(vis));
        dfs(i);

    }

    return 0;
}
