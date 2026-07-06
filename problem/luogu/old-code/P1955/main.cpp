#include <bits/stdc++.h>
using namespace std;

long long n;

struct DSU
{
    // 1. 数据源：pa[i] 存储 i 的父节点
    long long pa[100005];

    // 2. 初始化：每个人起初都是自己的老大
    void init(long long n)
    {
        for (long long i = 0; i <= n; i++)
            pa[i] = i;
    }

    // 3. 核心：找祖宗 + 路径压缩
    // 逻辑：找到根的同时，把路径上所有人的 parent 直接指向根
    long long find(long long x)
    {
        return pa[x] == x ? x : pa[x] = find(pa[x]);
    }

    // 4. 合并：把 x 的祖宗挂到 y 的祖宗下面
    void unite(long long x, long long y)
    {
        pa[find(x)] = find(y);
    }

    // 5. 判断：祖宗一样就是一家人
    bool connected(long long x, long long y)
    {
        return find(x) == find(y);
    }
} dsu;

void work()
{
    cin >> n;
    const long long maxn = n + 5;
    dsu.init(maxn);

    vector<int> nums;
    for (long long k = 1; k <= n; k++)
    {
        long long i, j, e;
        cin >> i >> j >> e;
        nums.push_back(i);
        nums.push_back(j);
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        auto get_id = [&](int x)
        {
            return lower_bound(nums.begin(), nums.end(), x) - nums.begin();
        };
        if (e == 1)
        {
            dsu.unite(get_id(i), get_id(j));
        }
        if (e == 0)
        {
            if (dsu.connected(get_id(i), get_id(j)))
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}

int main()
{
    long long t;
    cin >> t;
    while (t--)
        work();
    return 0;
}
