#include <bits/stdc++.h>
using namespace std;

// 类型别名，替代 define
using ll = long long;
using pii = pair<int, int>;

/**
 * 逻辑简述：
 * 1. 版本化拆点：对于每次赋值操作，给变量创建一个新编号（新版本），
 *    旧版本向新版本连边，边权记录符号变化。
 * 2. 约束建立：最后连一条从“最终版本”回到“初始版本”的边。
 * 3. 找环与判定：利用反向图找环，分析环内是否存在逻辑矛盾（奇环）或指向了 U 虚点。
 */

const int MAX_NODES = 200005 + 10;
const int VAL_UNKNOWN = 3;

// 全局存储结构
int current_version[MAX_NODES];
int node_total;
int final_val[MAX_NODES];
int belong_root[MAX_NODES];

vector<pii> adj[MAX_NODES];
vector<pii> rev_adj[MAX_NODES];
bitset<MAX_NODES> visited, is_on_cycle;
vector<vector<int>> all_cycles;
stack<int> dfs_stack;
bool found_cycle = false;

// 替代 eb 和内联 addEdge
inline void add_edge(int u, int v, int w)
{
    adj[u].push_back({v, w});
    rev_adj[v].push_back({u, w});
}

// 找环 DFS：在反向图上通过 DFS 寻找强连通分量/环
void find_cycle_dfs(int u, int rt)
{
    if (belong_root[u] == rt)
    {
        all_cycles.push_back(vector<int>());
        while (true)
        {
            int curr = dfs_stack.top();
            dfs_stack.pop();
            is_on_cycle[curr] = 1;
            all_cycles.back().push_back(curr);
            if (curr == u)
                break;
        }
        found_cycle = true;
        return;
    }
    else if (rev_adj[u].empty())
    {
        is_on_cycle[u] = 1;
        all_cycles.push_back({u});
        found_cycle = true;
        return;
    }

    dfs_stack.push(u);
    visited[u] = 1;
    belong_root[u] = rt;

    for (const auto &edge : rev_adj[u])
    {
        if (found_cycle)
            return;
        find_cycle_dfs(edge.first, rt);
    }
}

// 染色 DFS：将确定为 Unknown 的状态在依赖图中传播
inline void color_dfs(int u, bool set_u)
{
    final_val[u] = set_u ? VAL_UNKNOWN : 0;
    visited[u] = 1;
    for (const auto &edge : adj[u])
    {
        if (!is_on_cycle[edge.first])
        {
            color_dfs(edge.first, set_u);
        }
    }
}

// 分析环的性质：判断该连通块是否必须为 U
inline void process_cycle(int n, int m)
{
    int path_xor = 0;
    bool has_explicit_u = false;
    bool has_logic_conflict = false;

    const vector<int> &curr_cycle = all_cycles.back();
    // 定义常量节点编号
    const int T_node = n + m + 1;
    const int F_node = n + m + 2;
    const int U_node = n + m + 3;

    for (int u : curr_cycle)
    {
        if (u == U_node)
            has_explicit_u = true;

        // 判定已知常量与路径符号是否冲突
        if (u == T_node && !has_logic_conflict && path_xor)
            has_logic_conflict = true;
        else if (u == F_node && !has_logic_conflict && !path_xor)
            has_logic_conflict = true;

        for (const auto &edge : adj[u])
        {
            if (is_on_cycle[edge.first])
            {
                path_xor ^= edge.second;
                break;
            }
        }
    }

    // 只要有奇环 (path_xor=1) 或包含 U 节点，则整个连通块染色为 U
    bool must_be_u = path_xor || has_explicit_u || has_logic_conflict;
    for (int u : curr_cycle)
    {
        color_dfs(u, must_be_u);
    }
}

void solve()
{
    int n, m;
    if (!(cin >> n >> m))
        return;

    // 节点分配逻辑
    const int T_node = n + m + 1;
    const int F_node = n + m + 2;
    const int U_node = n + m + 3;

    node_total = n;
    visited.reset();
    is_on_cycle.reset();
    all_cycles.clear();

    // 清理上一轮的状态
    for (int i = 1; i <= U_node; i++)
    {
        adj[i].clear();
        rev_adj[i].clear();
        belong_root[i] = 0;
        final_val[i] = 0;
        if (i <= n)
            current_version[i] = i;
    }

    // 读入操作并建图
    for (int i = 1; i <= m; i++)
    {
        string op;
        int x;
        cin >> op >> x;
        if (op == "+" || op == "-")
        {
            int y;
            cin >> y;
            int w = (op == "-" ? 1 : 0);
            add_edge(current_version[y], ++node_total, w);
            current_version[x] = node_total;
        }
        else
        {
            int const_node = (op == "T" ? T_node : (op == "F" ? F_node : U_node));
            add_edge(const_node, ++node_total, 0);
            current_version[x] = node_total;
        }
    }

    // 核心约束：x_initial = x_final
    for (int i = 1; i <= n; i++)
    {
        add_edge(current_version[i], i, 0);
    }

    const int total_limit = n + m + 3;
    for (int i = 1; i <= total_limit; i++)
    {
        if (!visited[i])
        {
            while (!dfs_stack.empty())
                dfs_stack.pop();
            found_cycle = false;
            find_cycle_dfs(i, i);
            if (found_cycle)
                process_cycle(n, m);
        }
    }

    // 统计结果
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (final_val[i] == VAL_UNKNOWN)
            ans++;
    }
    cout << ans << endl;
}

int main()
{
    // 提升 I/O 效率
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_point_id, test_cases;
    if (cin >> test_point_id >> test_cases)
    {
        while (test_cases--)
        {
            solve();
        }
    }
    return 0;
}