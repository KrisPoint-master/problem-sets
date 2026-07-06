#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const int maxe = 1e6 + 5;

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
    void reset()
    {
        edge_cnt = 0;
        memset(h, -1, sizeof(h));
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

template <int N>
struct Kahn
{
    int indgree[N]; // 存点的入度的
    int seq[N];     // 排序好的序列
    int idx = 0;    // 下标
    stack<int> sta;

    /**
     * n : 最大的那个点的编号
     * 最小点的编号默认是1
     */
    void work(int n, linkList &e)
    {
        for (int i = 1; i <= n; i++)
            if (indgree[i] == 0)
                sta.push(i);
        while (!sta.empty())
        {
            int u = sta.top();
            seq[++idx] = u; // 排序
            sta.pop();
            for (int i = e.h[u]; i != -1; i = e[i].next)
            {
                int v = e[i].v;
                if (--indgree[v] == 0)
                    sta.push(v);
            }
        }
    }
};
Kahn<maxn> kahn;
map<int, int> ma;

int n, m;
void init()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int p, g;
        cin >> p >> g;
        int l = (p & g) ;
        if (ma[l])
        {
            continue;
        }
        ma[l]++;
        e.add(g, p);
        kahn.indgree[p]++;
    }
}
void reinit(Kahn<maxn> &kahn, linkList &l)
{
    n = m = 0;
    kahn.idx = 0;
    memset(kahn.indgree, 0, sizeof(kahn.indgree));
    memset(kahn.seq, 0, sizeof(kahn.seq));
    while (!kahn.sta.empty())
        kahn.sta.pop();
    l.reset();
}

void work()
{
    reinit(kahn, e);
    init();
    kahn.work(n, e);
    stack<int> s;
    for (int i = 1; i <= n; i++)
    {
        s.push(kahn.seq[i]);
    }
    while (!s.empty())
    {
        cout << s.top() << ' ';
        s.pop();
    }
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
        work();
    return 0;
}
