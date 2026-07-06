#include <bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
void print_array(int n, int *a) {}
#else
void print_array(int n, int *a)
{
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
#endif

int x_f[maxn]; // x_final
const int inf = INT64_MAX;

struct global
{
    int tid = 0;
    int n = 0, m = 0;
    int min_u;
} global;

struct logic_sentence
{
    int lsid = 0;
    char op;    // T,F,U,+,-
    int x_1;    // first arg
    char x_1_v; // ?
    int x_2;    // (choice) se arg
} ls[1000005];

void input();
void work();
void work34();
void work56();
void final_work();

int main(int argc, char const *argv[])
{
    int c, t;
    cin >> c >> t;
    while (t--)
    {
        global.tid++;
        input();
        if (c == 3 || c == 4)
        {
            work34();
            continue;
        }
        if (c == 5 || c == 6)
        {
            work56();
            continue;
        }
        final_work();
        work();
    }
    return 0;
}

void input()
{
    cin >> global.n >> global.m;
    for (int i = 1; i <= global.m; i++)
    {
        cin >> ls[i].op;
        if (ls[i].op == 'T' || ls[i].op == 'F' || ls[i].op == 'U')
        {
            cin >> ls[i].x_1;
            ls[i].x_1_v = ls[i].op;
        }
        if (ls[i].op == '+' || ls[i].op == '-')
        {
            cin >> ls[i].x_1 >> ls[i].x_2;
        }
    }
}
void dfs(int dep);
void work()
{
    global.min_u = INT32_MAX;
    dfs(1);
    cout << global.min_u << endl;
}

int b[1000005];
void work_out_arr(int n, int *a, int m, logic_sentence *ls);
void dfs(int dep)
{
    if (dep > global.n)
    {
        // print_array(global.n, b);
        work_out_arr(global.n, b, global.m, ls);
        return;
    }
    for (int i = 1; i <= 3; i++)
    {
        // x_i : T1 F2 U3
        b[dep] = i;
        dfs(dep + 1);
        b[dep] = 0;
    }
}

int x[100005]; // simulation

int logic_not(int val)
{
    if (val == 1)
        return 2; // !T = F
    if (val == 2)
        return 1; // !F = T
    return 3;     // !U = U
}

void work34()
{
    memset(x, -1, sizeof(x));
    int cnt = 0;
    int maxx1 = INT32_MIN;
    int minx1 = INT32_MAX;
    for (int i = 1; i <= global.m; i++)
    {
        maxx1 = max(maxx1, ls[i].x_1);
        minx1 = min(minx1, ls[i].x_1);
        if (ls[i].op == 'T')
        {
            x[ls[i].x_1] = 1;
        }
        if (ls[i].op == 'F')
        {
            x[ls[i].x_1] = 2;
        }
        if (ls[i].op == 'U')
        {
            x[ls[i].x_1] = 3;
        }
    }
    for (int i = minx1; i <= maxx1; i++)
    {
        if (x[i] == 3)
            cnt++;
    }

    cout << cnt << endl;
}

struct DSU
{
    vector<int> fa, sz;
    DSU(int n) : fa(n + 1), sz(n + 1, 1)
    {
        iota(fa.begin(), fa.end(), 0); // 初始化父节点为自己
    }
    int find(int x)
    { // 路径压缩
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }
    void unite(int x, int y)
    { // 按大小合并
        x = find(x), y = find(y);
        if (x == y)
            return;
        if (sz[x] < sz[y])
            swap(x, y);
        fa[y] = x;
        sz[x] += sz[y];
    }
    bool same(int x, int y)
    { // 判断是否同集合
        return find(x) == find(y);
    }
};
void work56()
{
    // cur[i]  i -> current val
    // U : 0
    vector<int> cur(global.n + 1);
    for (int i = 1; i <= global.n; i++)
        cur[i] = i;

    for (int i = 1; i <= global.m; i++)
    {
        if (ls[i].op == 'U')
        {
            cur[ls[i].x_1] = 0;
        }
        else if (ls[i].op == '+')
        {
            cur[ls[i].x_1] = cur[ls[i].x_2];
        }
    }

    DSU dsu(global.n);
    vector<bool> must_be_u(global.n + 1, false);

    for (int i = 1; i <= global.n; i++)
    {
        if (cur[i] == 0)
        {
            must_be_u[i] = true;
        }
        else
        {
            dsu.unite(i, cur[i]);
        }
    }

    for (int i = 1; i <= global.n; i++)
    {
        if (must_be_u[i])
        {
            must_be_u[dsu.find(i)] = true;
        }
    }

    int ans = 0;
    for (int i = 1; i <= global.n; i++)
    {
        if (must_be_u[dsu.find(i)])
        {
            ans++;
        }
    }
    cout << ans << endl;
}

void work_out_arr(int n, int *a, int m, logic_sentence *ls)
{
    for (int i = 1; i <= global.n; i++)
        x[i] = b[i];

    // ¬T=F, ¬F=T, ¬U=U.
    for (int i = 1; i <= m; i++)
    {
        if (ls[i].op == 'T')
        {
            x[ls[i].x_1] = 1;
        }
        if (ls[i].op == 'F')
        {
            x[ls[i].x_1] = 2;
        }
        if (ls[i].op == 'U')
        {
            x[ls[i].x_1] = 3;
        }
        if (ls[i].op == '+')
        {
            x[ls[i].x_1] = x[ls[i].x_2];
        }
        if (ls[i].op == '-')
        {
            x[ls[i].x_1] = logic_not(x[ls[i].x_2]);
        }
    }
    bool flag = true;
    int c_u = 0;
    for (int i = 1; i <= global.n; i++)
    {
        if (x[i] != b[i])
        {
            flag = false;
            break;
        }
        if (b[i] == 3)
            c_u++;
    }

    if (flag)
    {
        global.min_u = min(global.min_u, c_u);
    }
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

struct cir
{
    int u;
    int w;
} circle[maxn];
int top = 0;

int vis[maxn];

int dfs(int u, int fa)
{
    if (vis[u] == 1)
        return u;
    if (vis[u] == 2)
        return 0;

    vis[u] = 1;
    for (int i = e(u); i != -1; i = e[i].next)
    {
        int v = e[i].v;
        if (v == fa)
            continue;
        int t = dfs(v, u);
        if (t != 0)
        {
            circle[++top].u = u;
            circle[top].w = e[i].w;
            vis[u] = 2;
            if (t == u)
                return 0;
            return t;
        }
    }
    vis[u] = 2;
    return 0;
}

void final_work()
{
}