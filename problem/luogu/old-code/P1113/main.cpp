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
int n;
int idx, len[maxn];

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
int f[maxn];

int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> idx >> len[i];
        while (1)
        {
            cin >> temp;
            if (temp == 0)
                break;
            e.add(temp, idx);
            kahn.indgree[idx]++;
        }
    }
    kahn.work(n, e);
    // kahn.seq;
    return 0;
}
