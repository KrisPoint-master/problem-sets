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

    // 遍历点u 周围点
    template <typename U>
    void for_each(int u, U func)
    {
        for (int i = h[u]; i != -1; i = e[i].next)
            func(e[i].u, e[i].v, e[i].w); // u v w
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

int n, m;
int w[maxn];

int main(int argc, char const *argv[])
{
    cin >> n;
    m = n - 1;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        e.add2(a, b, 1);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }
    int ans = 0, m3 = 0;
    for (int i = 1; i <= n; i++)
    {
        int m1 = 0, m2 = 0, t1 = 0, t2 = 0; // max ci max t1 sum pow2 t2 pow sum
        for (int j = e(i); j != -1; j = e[j].next)
        {
            if (w[e[j].v] > m1)
                m2 = m1, m1 = w[e[j].v];
            else if (w[e[j].v] > m2)
                m2 = w[e[j].v];
            t1 = (t1 + w[e[j].v]) % 10007;
            t2 = (t2 + w[e[j].v] * w[e[j].v]) % 10007;
        }
        t1 = t1 * t1 % 10007;
        ans = (ans + t1 + 10007 - t2) % 10007;
        if (m3 < m1 * m2)
            m3 = m1 * m2;
    }
    cout << m3 << " " << ans << endl;

    return 0;
}
