#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 定义矛盾关系的结构体
struct Edge
{
    int u, v, w;
};

// 排序规则：按怨气值从大到小排序
bool compareEdges(const Edge &a, const Edge &b)
{
    return a.w > b.w;
}

// 并查集相关变量
int parent[20005];
int enemy[20005]; // 记录每个罪犯的一个敌人

// 并查集查找函数（带路径压缩）
int find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

// 并查集合并函数
void unite(int x, int y)
{
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY)
    {
        parent[rootX] = rootY;
    }
}

int main()
{
    // 优化输入输出速度
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    // 1. 贪心策略：按怨气值降序排列
    sort(edges.begin(), edges.end(), compareEdges);

    // 2. 初始化并查集
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        enemy[i] = 0; // 初始没有敌人
    }

    // 3. 逐个处理矛盾
    for (int i = 0; i < m; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;

        // 如果两人已经在同一个集合，说明冲突不可避免
        if (find(u) == find(v))
        {
            cout << edges[i].w << endl;
            return 0;
        }

        // 维护“敌人的敌人是朋友”
        // 把 u 和 v 的敌人放在一起
        if (enemy[u] == 0)
        {
            enemy[u] = v;
        }
        else
        {
            unite(enemy[u], v);
        }

        // 把 v 和 u 的敌人放在一起
        if (enemy[v] == 0)
        {
            enemy[v] = u;
        }
        else
        {
            unite(enemy[v], u);
        }
    }

    // 如果遍历完所有矛盾都没有冲突，输出 0
    cout << 0 << endl;

    return 0;
}
/// AI代写，思路我想的