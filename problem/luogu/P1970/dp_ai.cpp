#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // 优化输入输出
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n))
        return 0;

    vector<int> h(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> h[i];
    }

    // up[i] 表示以 h[i] 结尾且最后一步是上升的最长序列长度
    // down[i] 表示以 h[i] 结尾且最后一步是下降的最长序列长度
    vector<int> up(n, 1);
    vector<int> down(n, 1);

    int ans = 1;

    // O(n^2) 的双重循环
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (h[i] > h[j])
            {
                up[i] = max(up[i], down[j] + 1);
            }
            else if (h[i] < h[j])
            {
                down[i] = max(down[i], up[j] + 1);
            }
        }
        ans = max({ans, up[i], down[i]});
    }

    cout << ans << "\n";

    return 0;
}