#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5; // 注意：根据题目要求调整了大小
const int maxe = 2e5 + 5;

// 链式前向星结构
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
long long sum = 0;        // 存储最终答案：所有 d(i, j) 的总和
vector<int> back_history; // 存储当前路径产生的所有前缀按位或值 s_i
int vis[maxn];            // 标记数组，防止路径搜索中出现回路（虽然题目保证 u < v 是 DAG）
long long max_d = -1;     // 存储当前城市对 (s, t) 之间的最大疲劳度

vector<int> debug;

/**
 * @brief 深度优先搜索所有路径
 * @param s 起点
 * @param t 终点
 * @param u 当前所在城市
 * @param cut_or 当前路径到目前为止的累计按位或值
 */
void dfs(int s, int t, int u, int cut_or)
{
    // 如果当前城市就是目标城市
    if (u == t)
    {
        debug.push_back(u);
        for (auto iter : debug)
        {
            cout << iter << " ";
        }
        cout << " :  or :" << cut_or << "    mex{s_1,s_2,...s_n} : ";
        if (back_history.empty())
        {
            max_d = max(max_d, 0LL); // 对应 d(s, s) = 0
            return;
        }

        // 复制一份历史记录进行排序，用于计算 MEX
        vector<int> temp = back_history;
        sort(temp.begin(), temp.end());

        // 计算 MEX(s_1, s_2, ..., s_{k-1})
        int mex_val = 0;
        for (int val : temp)
        {
            if (val == mex_val)
                mex_val++;
            else if (val > mex_val)
                break;
        }
        // 更新 s 到 t 的最大疲劳度
        max_d = max(max_d, (long long)mex_val);
        cout << mex_val << "   max_pl  :  " << max_d << endl;
        debug.pop_back();
        return;
    }

    vis[u] = 1; // 标记当前点已访问

    // 遍历当前点的所有出边
    for (int i = e(u); i != -1; i = e[i].next)
    {
        int v = e[i].v;
        if (!vis[v])
        {
            int now_or = cut_or | e[i].w; // 计算新的按位或值 s_i
            back_history.push_back(now_or);
            debug.push_back(u);
            dfs(s, t, v, now_or);
            debug.pop_back();
            back_history.pop_back(); // 回溯：弹出当前边的或值
        }
    }

    vis[u] = 0; // 【关键】回溯：清除访问标记，允许其他路径经过此点
}

int main()
{
    // 优化输入
    ios::sync_with_stdio(false);
    cin.tie(0);

    if (!(cin >> n >> m))
        return 0;

    for (int i = 1; i <= m; i++)
    {
        int p, q, w;
        cin >> p >> q >> w;
        e.add(p, q, w);
    }

    // 遍历所有城市对 (i, j)
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            cout << endl
                 << endl;
            cout << "i:" << i << " j:" << j << " :" << endl;
            if (i == j)
            {
                cout << "jump, i == j, d(s,t)= 0" << endl;
                continue; // 题目规定 d(s, s) = 0，不影响总和
            }
            max_d = -1; // 重置当前城市对的最大距离
            back_history.clear();

            // 注意：因为题目保证 u < v，只有 i < j 时才可能连通
            if (i < j)
            {
                debug.clear();
                dfs(i, j, i, 0);
            }

            // 如果 max_d 仍为 -1，说明不可达，d(i, j) = -1
            // 否则将结果累加到总和
            if (max_d != -1)
            {
                sum += max_d;
            }
            else
            {
                cout << "d(s,t)= -1" << endl;
                sum += (-1);
            }
        }
    }

    cout << sum << endl;

    return 0;
}