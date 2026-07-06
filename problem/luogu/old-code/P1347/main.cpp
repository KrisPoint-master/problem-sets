#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
const int maxe = 1e6 + 5;

// 完全保留你的 linkList 封装
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
    edge &operator[](int i) { return e[i]; }
    int operator()(int u) { return h[u]; }
} e;

// 完全保留你的 TopSort 封装，仅在 topsort 函数内增加状态判断
struct TopSort
{
    int in_degree[maxn];
    int temp_in[maxn]; // 备份入度，防止修改原始数据
    std::queue<int> q;
    std::vector<int> sorted;

    // 返回值：0-关系不确定，1-确定唯一序列，2-发现矛盾（有环）
    int topsort(int n)
    {
        while (!q.empty())
            q.pop();
        sorted.clear();
        memcpy(temp_in, in_degree, sizeof(in_degree));

        for (int i = 1; i <= n; ++i)
        {
            if (temp_in[i] == 0)
                q.push(i);
        }

        bool uncertain = false;
        while (!q.empty())
        {
            if (q.size() > 1)
                uncertain = true; // 同一时刻有多个入度为0的点，关系不唯一
            int u = q.front();
            q.pop();
            sorted.push_back(u);

            for (int i = e.h[u]; ~i; i = e[i].next)
            {
                int v = e[i].v;
                temp_in[v]--;
                if (temp_in[v] == 0)
                    q.push(v);
            }
        }

        if (sorted.size() < n)
            return 2;
        if (uncertain)
            return 0;
        return 1;
    }
} topsort;

int n, m;
int finished = 0;

void print(int op, int x, string a = "")
{
    if (op == 1)
    {
        printf("Sorted sequence determined after %d relations: %s.\n", x, a.c_str());
    }
    else if (op == 2)
    {
        printf("Inconsistency found after %d relations.\n", x);
    }
    else if (op == 3)
    {
        printf("Sorted sequence cannot be determined.\n");
    }
}

void init()
{
    if (!(cin >> n >> m) || (n == 0 && m == 0))
        exit(0);

    for (int i = 1; i <= m; i++)
    {
        char str[5];
        scanf("%s", str);
        if (finished)
            continue;

        int u = str[0] - 'A' + 1;
        int v = str[2] - 'A' + 1;

        e.add(u, v);
        topsort.in_degree[v]++;

        int res = topsort.topsort(n);
        if (res == 1)
        {
            string ans = "";
            for (int x : topsort.sorted)
                ans += (char)(x + 'A' - 1);
            print(1, i, ans);
            finished = 1;
        }
        else if (res == 2)
        {
            print(2, i);
            finished = 2;
        }
    }

    if (!finished)
        print(3, 0);
}

int main()
{
    init();
    return 0;
}