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
} e,ae;


int in_deg[maxn];
int out_deg[maxn];
long long ts[maxn];
int tssize;
int n,m;
long long f[maxn];

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
            --in_deg[v];
            if(in_deg[v] == 0) q.push(v);
        }
    }
}

#ifdef ONLINE_JUDGE
void debug(long long *arr,int n) {}
#else
void debug(long long *arr,int n){for (int i = 1; i <= n; i++) cout << arr[i] << " ";cout << endl;}
#endif

const long long mod = 80112002;

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u,v;
        cin >> u >> v;
        in_deg[u] ++;
        out_deg[v] ++;
        e.add(v,u);
        ae.add(u,v);
    }
    topsort();
    debug(ts,tssize);

    f[ts[1]] = 1;
    int ans= 0;
    for (int i = 2; i <= tssize; i++)
    {
        int u = ts[i];
        int cnt = 0;
        for(int j = ae(u);j != -1;j = ae[j].next)
        {
            int v = ae[j].v;
            cnt ++;
            f[u] += f[v];
            f[u] %= mod;
        }
        if(cnt == 0)
        {
            f[u] = 1;
        }
        if(out_deg[u] == 0) {
            ans += f[u];
            ans %= mod;
        }
    }
    debug(f,n);
    cout << ans << endl;
    return 0;
}
