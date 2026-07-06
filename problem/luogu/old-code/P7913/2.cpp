#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 计算给定航班在k个廊桥时能停靠的最大数量
vector<int> calculate_max(const vector<pair<int, int>> &flights, int max_k)
{
    int m = flights.size();
    vector<int> res(max_k + 1, 0);

    // 按抵达时间排序航班
    vector<pair<int, int>> sorted_flights = flights;
    sort(sorted_flights.begin(), sorted_flights.end());

    // 对于每个可能的廊桥数量k
    for (int k = 1; k <= max_k; ++k)
    {
        priority_queue<int, vector<int>, greater<int>> pq; // 记录廊桥空闲时间
        int count = 0;

        for (const auto &flight : sorted_flights)
        {
            int arrive = flight.first;
            int depart = flight.second;

            // 释放已空闲的廊桥
            while (!pq.empty() && pq.top() <= arrive)
            {
                pq.pop();
            }

            // 如果有空闲廊桥
            if (pq.size() < k)
            {
                count++;
                pq.push(depart);
            }
        }

        res[k] = count;
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m1, m2;
    cin >> n >> m1 >> m2;

    // 读取国内航班
    vector<pair<int, int>> domestic(m1);
    for (int i = 0; i < m1; ++i)
    {
        cin >> domestic[i].first >> domestic[i].second;
    }

    // 读取国际航班
    vector<pair<int, int>> international(m2);
    for (int i = 0; i < m2; ++i)
    {
        cin >> international[i].first >> international[i].second;
    }

    // 计算国内和国际航班在不同廊桥数量下的最大停靠数
    vector<int> domestic_max = calculate_max(domestic, n);
    vector<int> international_max = calculate_max(international, n);

    // 尝试所有可能的分配方案，找到最大值
    int max_total = 0;
    for (int k = 0; k <= n; ++k)
    {
        int total = domestic_max[k] + international_max[n - k];
        max_total = max(max_total, total);
    }

    cout << max_total << endl;

    return 0;
}