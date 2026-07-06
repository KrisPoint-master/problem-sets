#include <bits/stdc++.h>
using namespace std;

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
} e;

int in_deg[maxn];
int s[maxn];
long long ts[maxn];
int tssize;
int n,m;
long long f[maxn];
int c;
long long mem[maxn][4];

void topsort()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if(in_deg[i] == 0) q.push(i);
    }
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        tssize++;
        ts[tssize] = u;

        for(int i = e(u);i != -1;i = e[i].next)
        {
            int v = e[i].v;
            f[v] = max(f[v],f[u]+e[i].w);
            --in_deg[v];
            if(in_deg[v] == 0) q.push(v);
        }
    }
}

int main(int argc, char const *argv[])
{
    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        f[i] = s[i];
    }

    for (int i = 1; i <= c; i++)
    {
        cin >> mem[i][1] >> mem[i][2] >> mem[i][3];
        in_deg[mem[i][2]]++;
        e.add(mem[i][1],mem[i][2],mem[i][3]);
    }

    topsort();

    for (int i = 1; i <= n; i++)
    {
        cout << f[i] << endl;
    }
    
    

    return 0;
}

