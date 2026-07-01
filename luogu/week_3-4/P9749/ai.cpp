#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    // 优化输入输出
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long d;
    cin >> n >> d;

    vector<long long> v(n);
    // 读入距离，并直接处理成从起点到该站点的“前缀和总距离”
    v[1] = 0;
    for (int i = 1; i < n; i++)
    {
        long long dist;
        cin >> dist;
        v[i + 1] = v[i] + dist; // v[i] 表示到站点 i 的总距离
    }

    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    long long total_cost = 0;   // 总花费
    long long cur_dist = 0;     // 当前已买的油支持的最大公里数
    long long min_price = a[1]; // 历史最低油价

    for (int i = 1; i < n; i++)
    {
        // 更新历史最低油价
        min_price = min(min_price, a[i]);

        // 如果当前的油支撑不到下一个站点
        if (cur_dist < v[i + 1])
        {
            long long need_dist = v[i + 1] - cur_dist; // 还需要走多少公里
            // 向上取整计算需要多少升油：(A + B - 1) / B
            long long need_oil = (need_dist + d - 1) / d;

            total_cost += need_oil * min_price; // 累加花费
            cur_dist += need_oil * d;           // 更新能走的总距离
        }
    }

    cout << total_cost << "\n";

    return 0;
}