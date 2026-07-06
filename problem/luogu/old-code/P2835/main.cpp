#include <bits/stdc++.h>
using namespace std;
template <typename type>
inline void read(type &x)
{
    x = 0;
    bool flag(0);
    char ch = getchar();
    while (!isdigit(ch))
        flag = ch == '-', ch = getchar();
    while (isdigit(ch))
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    flag ? x = -x : 0;
}

template <typename type>
inline void write(type x, bool mode = 1)
{
    x < 0 ? x = -x, putchar('-') : 0;
    static short Stack[50], top(0);
    do
        Stack[++top] = x % 10, x /= 10;
    while (x);
    while (top)
        putchar(Stack[top--] | 48);
    mode ? putchar('\n') : putchar(' ');
}
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

int dfn[maxn], low[maxn];
int color[maxn], color_cnt = 0, DFN = 0; // 每个点的颜色,也就是属于的连通分量的编号
bool instack[maxn];
stack<int> sta; // 栈
void tarjan(int u)
{
    dfn[u] = low[u] = ++DFN; // 为节点u设定次序编号和low初值
    sta.push(u);             // 将节点u压入栈中
    for (int i = e(u); ~i; i = e[i].next)
    {
        int v = e[i].v;
        if (!dfn[v])
        {              // 如果节点v未被访问过
            tarjan(v); // 继续向下找
            low[u] = min(low[u], low[v]);
        }
        else if (instack[v])
        {                                 // 反祖边,节点v还在栈内
            low[u] = min(low[u], dfn[v]); // low[u] = min(low[u], low[v]) 理论上这样写也可以
        }
    }
    if (dfn[u] == low[u])
    { // 如果节点u是强连通分量的根
        color_cnt++;
        int t = -1;
        do
        {
            t = sta.top();
            sta.pop();
            instack[t] = 0; // 将v退栈，为该强连通分量中一个顶点
            color[t] = color_cnt;
        } while (t != u);
    }
}

int degree[maxn];

int main(int argc, char **argv)
{
    int n;
    read(n);
    for (int i = 1; i <= n; i++)
    {
        int v;
        while (1)
        {
            read(v);
            if (v == 0)
                break;
            e.add(i, v);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i])
            tarjan(i);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = e(i); j != -1; j = e[j].next)
        {
            if (color[i] != color[j])
            {
                degree[color[j]]++;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= color_cnt; i++)
    {
        if (degree[i] == 0)
            ans++;
    }
    cout << ans;

    return 0;
}