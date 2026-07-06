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

long long in_deg[maxn];
int tssize;
long long ts[maxn];
int n,m;

long long area[maxn];
long long point[maxn];

void topsort()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if(in_deg[point[i]] == 0) q.push(point[i]);
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
            if(in_deg[v] == 0 && area[v]) q.push(v);
        }
    }
}

#ifdef ONLINE_JUDGE
void debug(long long *arr,int n) {}
#else
void debug(long long *arr,int n){for (int i = 1; i <= n; i++) cout << arr[i] << " ";cout << endl;}
#endif

int main(int argc, const char** argv)
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x,m;
        cin >> x >> m;
        area[x] = 1;
        point[i] = x;
        for (int j = 1; j <= m; j++)
        {
            int v;
            cin >> v;
            in_deg[v] ++;
            e.add(x,v);   
        }
    }

    topsort();

    debug(ts,tssize);

    if(tssize == n) cout << "YES" << endl;
    else cout << n-tssize << endl;
    return 0;
}