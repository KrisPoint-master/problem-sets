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

typedef struct pair_uv {int u,v;}pair_uv;
vector<pair_uv> ans;

void tarjan_cutedge(int u,int fa) {
    int child = 0;
    dfn[u] = low[u] = ++dfs_time;
    vis[u] = 1; 
    for(int i = e(u);i != -1;i = e[i].next) {
        int v = e[i].v;

        if( v == fa) continue;
        
        if( vis[v] == 0)  {
            child++;
            tarjan_cutedge(v,u);
            
            low[u] = min(low[u],low[v]);

            if( low[v] > dfn[u]) 
            {
                ans.push_back({u,v});
                // cout << u << " " << v << endl;
            }
        }
        else { 
            low[u] = min(low[u],dfn[v]);
        }
    }
}

bool cmp(pair_uv a,pair_uv b)
{
    if(a.u == b.u)
        return a.v < b.v;
    return a.u < b.u;
}

int main(int argc, char const *argv[])
{
    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u,v;
        cin >> u >> v;
        e.add2(u,v);
    }

    tarjan_cutedge(1,0);

    sort(ans.begin(),ans.end(),cmp);

    for(auto iter : ans)
    {
        cout << iter.u << " " << iter.v << endl;
    }
    
    return 0;
}
