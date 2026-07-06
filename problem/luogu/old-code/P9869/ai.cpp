#include <bits/stdc++.h>
using namespace std;

/**
 * 核心逻辑解析：
 * 1. 映射简化：无论经过多少次操作，每个变量最终的状态只有 5 种可能：
 *    确定的 T, F, U，或者等于某个初始变量 x[j] 的原值或取反值。
 * 2. 图论建模：
 *    - 每个变量看作一个节点。
 *    - 如果最终 x[i] = x[j]，连一条边 (i, j)，边权 w = 0 (同号)。
 *    - 如果最终 x[i] = !x[j]，连一条边 (i, j)，边权 w = 1 (异或/异号)。
 * 3. U 的判定准则：
 *    - 显式 U：某连通块内有变量被直接赋值为 'U'。
 *    - 逻辑矛盾（奇环）：在基环树中，如果环上所有边的异或和为 1，
 *      意味着推导出了 x[i] = !x[i]，这在逻辑上只有 x[i] = U 能成立。
 */

const int MAXN = 1e5 + 5;
const int INF_VAL = 1e9; // 偏移量，用于区分常量与变量索引

int n, m;
int x_final[MAXN]; // 记录最终状态：正数表示 x[j]，负数表示 !x[j]，1e9+ 表示常量

// 链式前向星：存储变量间的等价/对立关系
struct LinkList
{
    struct Edge
    {
        int to, w, next;
    } e[MAXN << 1];
    int h[MAXN], cnt;
    void init(int n)
    {
        cnt = 0;
        fill(h, h + n + 1, -1);
    }
    void add(int u, int v, int w)
    {
        e[cnt] = {v, w, h[u]};
        h[u] = cnt++;
    }
} g;

int vis[MAXN];       // DFS 访问状态：0 未访问，1 栈中（搜索中），2 已完全访问
int val[MAXN];       // 存储节点相对于连通块起点的逻辑状态（0：同号，1：异号）
int type[MAXN];      // 记录变量被赋予的常量类型：1:T, 2:F, 3:U, 0:引用变量
vector<int> comp;    // 存储当前连通块内的所有节点
bool has_odd_cycle;  // 标记当前连通块是否存在奇环（逻辑矛盾）
bool has_explicit_u; // 标记当前连通块是否包含被赋值为 'U' 的点

/**
 * DFS 遍历连通块
 * @param u 当前节点
 * @param cur_val 当前节点相对于起点的符号（0或1）
 */
void dfs(int u, int cur_val)
{
    vis[u] = 1;
    val[u] = cur_val;
    comp.push_back(u);
    if (type[u] == 3)
        has_explicit_u = true;

    for (int i = g.h[u]; ~i; i = g.e[i].next)
    {
        int v = g.e[i].to;
        int w = g.e[i].w; // w=0: v=u; w=1: v=!u

        if (vis[v] == 0)
        {
            dfs(v, cur_val ^ w);
        }
        else if (vis[v] == 1)
        {
            // 发现环！判定逻辑：
            // 若 (起点到u的路径) ^ (起点到v的路径) ^ (u到v的边) != 0
            // 则说明从起点出发经过两条路径到达 v 的符号不一致 -> 产生逻辑矛盾（奇环）
            if ((val[u] ^ val[v] ^ w) != 0)
            {
                has_odd_cycle = true;
            }
        }
    }
    vis[u] = 2;
}

void solve()
{
    cin >> n >> m;
    g.init(n);

    // 初始化每个变量指向自己
    for (int i = 1; i <= n; i++)
    {
        x_final[i] = i;
        type[i] = 0;
        vis[i] = 0;
    }

    // --- 阶段 1：模拟赋值过程 ---
    for (int k = 0; k < m; k++)
    {
        char op;
        int u, v;
        cin >> op;
        if (op == 'T')
        {
            cin >> u;
            x_final[u] = INF_VAL;
            type[u] = 1;
        }
        else if (op == 'F')
        {
            cin >> u;
            x_final[u] = INF_VAL + 1;
            type[u] = 2;
        }
        else if (op == 'U')
        {
            cin >> u;
            x_final[u] = INF_VAL + 2;
            type[u] = 3;
        }
        else if (op == '+')
        {
            cin >> u >> v;
            x_final[u] = x_final[v];
            type[u] = type[v];
        }
        else if (op == '-')
        {
            cin >> u >> v;
            // 处理取反逻辑
            if (abs(x_final[v]) <= n)
                x_final[u] = -x_final[v];
            else if (x_final[v] == INF_VAL)
                x_final[u] = INF_VAL + 1;
            else if (x_final[v] == INF_VAL + 1)
                x_final[u] = INF_VAL;
            else
                x_final[u] = INF_VAL + 2;

            // 更新常量类型：!T = F, !F = T, !U = U
            if (type[v] == 1)
                type[u] = 2;
            else if (type[v] == 2)
                type[u] = 1;
            else
                type[u] = type[v];
        }
    }

    // --- 阶段 2：建图 ---
    for (int i = 1; i <= n; i++)
    {
        // 如果 x_i 最终依赖于某个初始变量 x_j (正或负)
        if (abs(x_final[i]) <= n)
        {
            int u = i;
            int v = abs(x_final[i]);
            int w = (x_final[i] < 0 ? 1 : 0); // 负数代表有取反操作，权值为 1
            g.add(u, v, w);
            g.add(v, u, w);
        }
    }

    // --- 阶段 3：图论分析 ---
    int total_u = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            comp.clear();
            has_odd_cycle = false;
            has_explicit_u = false;

            dfs(i, 0);

            // 如果该连通块有奇环（x = !x）或者有显式 U 赋值
            // 那么整个连通块的所有初始变量都必须设为 U，以满足“最终值=初值”
            if (has_odd_cycle || has_explicit_u)
            {
                total_u += comp.size();
            }
        }
    }
    cout << total_u << endl;
}

int main()
{
    // 关流同步提升性能
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c, t;
    cin >> c >> t; // 测试点编号 c 与组数 t
    while (t--)
    {
        solve();
    }
    return 0;
}