//Author by [Rainboy](https://github.com/rainboylvx) 
//date: 2024-09-25 20:56:07
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifndef DEBUG
#define log(...)
#else
#define log(args...) { cout << "LINE:" << __LINE__ << " : ";string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}

template<typename T>
void err(istream_iterator<string> it, T a) {
cerr << *it << " = " << a << "\n";
}

template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
cerr << *it << " = " << a << ", ";
err(++it, args...);
}
#endif
int n,m;
int x,y;

const int maxn = 1e6+5;
const int maxe = 1e6+5;
int a[maxn];

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

bool vis[maxn];
int del;
bool dfs(int u) {
    vis[u] = 1;
    if( u == y ) {
        return 1;
    }
    for(int i = e.h[u];i!=-1;i= e[i].next) {
        int v =  e[i].v;
        if(v == del || vis[v]) continue;
        if( dfs(v)) 
            return 1;
    }
    return 0;
}


int main () {
    std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); // 关闭io同步
    std::cin >> n >> m;
    for(int i = 1;i <= m ;++i ) // i: 1->m
    {
        int u,v;
        std::cin >> u >> v;
        e.add2(u,v);
    }
    std::cin >> x >> y;
    int ans=  0;
    for(int i = 1;i <= n ;++i ) // i: 1->n
    {
        if( i == x || i == y) continue;
        memset(vis,0,sizeof(vis));
        del = i;
        bool ret = dfs(x);
        ans += !ret;
    }
    std::cout << ans << "\n";

    return 0;
}
