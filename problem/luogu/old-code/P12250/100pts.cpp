#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

const int MAXN = 30005;

// 定义 bitset，大小根据题目范围设定
typedef bitset<MAXN> Mask;

Mask Reach[MAXN]; // Reach[u]: u 能够到达的所有点集合
Mask H1[MAXN];    // H1[u]: 从 u 出发，先走若干条(>=0) 0边后能到达的点集
Mask H2[MAXN];    // H2[u]: 从 u 出发，先走若干条 0 边，再走一条 1 边，再走任意边能到达的点集

vector<int> adj[MAXN];
vector<int> zero_adj[MAXN];
vector<int> one_adj[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(v);
        if (w == 0)
            zero_adj[u].push_back(v);
        if (w == 1)
            one_adj[u].push_back(v);
    }

    // 因为 u < v，我们从 n 到 1 倒着遍历进行 DP 即可
    for (int u = n; u >= 1; --u)
    {
        // 1. 计算 Reach
        Reach[u].set(u); // 自己可以到自己
        for (int v : adj[u])
        {
            Reach[u] |= Reach[v];
        }

        // 2. 计算 H1
        // H1 表示先经过一段全 0 路径，这决定了 mex 是否能跳过 0
        H1[u] = Reach[u];
        for (int v : zero_adj[u])
        {
            H1[u] |= H1[v];
        }

        // 3. 计算 H2
        // H2 表示路径前缀经历了 0，然后经历了 1（mex 至少为 2）
        for (int y : one_adj[u])
        {
            H2[u] |= H1[y];
        }
        for (int v : zero_adj[u])
        {
            H2[u] |= H2[v];
        }
    }

    long long total_sum = 0;
    for (int s = 1; s <= n; ++s)
    {
        Mask good1, good2;

        // 只有第一步走 0 边，才有可能让 mex > 0
        for (int v : zero_adj[s])
        {
            good1 |= H1[v];
            good2 |= H2[v];
        }

        int cnt_reach = Reach[s].count() - 1;  // 可达点的数量（不含自己）
        int cnt_unreach = (n - 1) - cnt_reach; // 不可达点的数量

        int cnt_mex_ge_1 = good1.count();
        int cnt_mex_ge_2 = good2.count();

        // mex=1 的个数 = (mex>=1 的个数) - (mex>=2 的个数)
        int cnt_only1 = cnt_mex_ge_1 - cnt_mex_ge_2;

        // 距离计算逻辑：
        // d(s, t) = 2 if t in good2
        // d(s, t) = 1 if t in good1 but not good2
        // d(s, t) = 0 if t is reachable but not in good1
        // d(s, t) = -1 if t is not reachable

        total_sum += 1LL * cnt_only1 * 1;
        total_sum += 1LL * cnt_mex_ge_2 * 2;
        total_sum += 1LL * cnt_unreach * -1;
    }

    cout << total_sum << endl;

    return 0;
}