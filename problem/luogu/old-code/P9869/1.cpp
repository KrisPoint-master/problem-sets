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
        work_out_arr(global.n, b, global.m, ls);
        return;
    }
    for (int i = 1; i <= 3; i++)
    {
        b[dep] = i;
        dfs(dep + 1);
        b[dep] = 0;
    }
}

int x[100005]; // simulation

int logic_not(int val)
{
    if (val == 1)
        return 2;
    if (val == 2)
        return 1;
    return 3;
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
            x[ls[i].x_1] = 1;
        if (ls[i].op == 'F')
            x[ls[i].x_1] = 2;
        if (ls[i].op == 'U')
            x[ls[i].x_1] = 3;
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
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x)
    {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }
    void unite(int x, int y)
    {
        x = find(x), y = find(y);
        if (x == y)
            return;
        if (sz[x] < sz[y])
            swap(x, y);
        fa[y] = x;
        sz[x] += sz[y];
    }
    bool same(int x, int y)
    {
        return find(x) == find(y);
    }
};

void work56()
{
    vector<int> cur(global.n + 1);
    for (int i = 1; i <= global.n; i++)
        cur[i] = i;

    for (int i = 1; i <= global.m; i++)
    {
        if (ls[i].op == 'U')
            cur[ls[i].x_1] = 0;
        else if (ls[i].op == '+')
            cur[ls[i].x_1] = cur[ls[i].x_2];
    }

    DSU dsu(global.n);
    vector<bool> must_be_u(global.n + 1, false);

    for (int i = 1; i <= global.n; i++)
    {
        if (cur[i] == 0)
            must_be_u[i] = true;
        else
            dsu.unite(i, cur[i]);
    }

    for (int i = 1; i <= global.n; i++)
    {
        if (must_be_u[i])
            must_be_u[dsu.find(i)] = true;
    }

    int ans = 0;
    for (int i = 1; i <= global.n; i++)
    {
        if (must_be_u[dsu.find(i)])
            ans++;
    }
    cout << ans << endl;
}

void work_out_arr(int n, int *a, int m, logic_sentence *ls)
{
    for (int i = 1; i <= global.n; i++)
        x[i] = b[i];
    for (int i = 1; i <= m; i++)
    {
        if (ls[i].op == 'T')
            x[ls[i].x_1] = 1;
        if (ls[i].op == 'F')
            x[ls[i].x_1] = 2;
        if (ls[i].op == 'U')
            x[ls[i].x_1] = 3;
        if (ls[i].op == '+')
            x[ls[i].x_1] = x[ls[i].x_2];
        if (ls[i].op == '-')
            x[ls[i].x_1] = logic_not(x[ls[i].x_2]);
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
        global.min_u = min(global.min_u, c_u);
}

// AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
// final overover

const int maxn = 1e6 + 5;
const int maxe = 1e6 + 5;
const int INF_VAL = 1e9;

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
    // 下标访问
    edge &operator[](int i) { return e[i]; }
    // 返回head[u]
    int operator()(int u) { return h[u]; }
} e;

int vis[maxn]; // DFS 访问状态：0 未访问，1 栈中，2 已完全访问

int x_final[maxn];
int type_ff[maxn];
int val_ff[maxn];
vector<int> circle;
bool flag_ff;
bool flag2_ff;

void dfs_ff(int u, int cur_val)
{
    vis[u] = 1;
    val_ff[u] = cur_val;
    circle.push_back(u);
    if (type_ff[u] == 3)
        flag2_ff = true;

    for (int i = e(u); i != -1; i = e[i].next)
    {
        int v = e[i].v;
        int w = e[i].w;

        if (vis[v] == 0)
        {
            dfs_ff(v, cur_val ^ w);
        }
        else if (vis[v] == 1)
        {
            // 判定奇环逻辑
            if ((val_ff[u] ^ val_ff[v] ^ w) != 0)
            {
                flag_ff = true;
            }
        }
    }
    vis[u] = 2;
}

void final_work()
{
    // ===== 关键修复：多组测试数据必须彻底清空 =====
    e.edge_cnt = 0; // 清空边的数量
    for (int i = 1; i <= global.n; i++)
    {
        e.h[i] = -1;    // 清空邻接表表头
        x_final[i] = i; // 初始都指向自己
        type_ff[i] = 0; // 清空类型记录
        vis[i] = 0;     // 清空访问状态
    }

    for (int k = 1; k <= global.m; k++)
    {
        char op = ls[k].op;
        int u = ls[k].x_1;
        int v = ls[k].x_2;

        if (op == 'T')
        {
            x_final[u] = INF_VAL;
            type_ff[u] = 1;
        }
        else if (op == 'F')
        {
            x_final[u] = INF_VAL + 1;
            type_ff[u] = 2;
        }
        else if (op == 'U')
        {
            x_final[u] = INF_VAL + 2;
            type_ff[u] = 3;
        }
        else if (op == '+')
        {
            x_final[u] = x_final[v];
            type_ff[u] = type_ff[v];
        }
        else if (op == '-')
        {
            if (abs(x_final[v]) <= global.n)
                x_final[u] = -x_final[v];
            else if (x_final[v] == INF_VAL)
                x_final[u] = INF_VAL + 1;
            else if (x_final[v] == INF_VAL + 1)
                x_final[u] = INF_VAL;
            else
                x_final[u] = INF_VAL + 2;

            if (type_ff[v] == 1)
                type_ff[u] = 2;
            else if (type_ff[v] == 2)
                type_ff[u] = 1;
            else
                type_ff[u] = type_ff[v];
        }
    }

    for (int i = 1; i <= global.n; i++)
    {
        if (abs(x_final[i]) <= global.n) // is a xi = xj
        {
            int u = i;
            int v = abs(x_final[i]);
            int w = (x_final[i] < 0 ? 1 : 0);
            e.add(u, v, w);
            e.add(v, u, w);
        }
    }

    int total_u = 0;
    for (int i = 1; i <= global.n; i++)
    {
        if (!vis[i])
        {
            circle.clear();
            flag_ff = false;
            flag2_ff = false;

            dfs_ff(i, 0);

            if (flag_ff || flag2_ff)
            {
                total_u += circle.size();
            }
        }
    }
    cout << total_u << endl;
}