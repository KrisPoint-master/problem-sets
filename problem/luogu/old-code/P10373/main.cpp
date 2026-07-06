#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    // 优化输入输出
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;

    ll current_M = 1;
    ll current_sum = 0; // 存储当前完整块的总和 sum_{k=1}^{M-1} k*((k+1)^3 - k^3)
    ll last_x_M = 0;    // 上一个 x 对应的最大立方根 M

    while (q--)
    {
        ll x;
        cin >> x;

        // 找到当前 x 对应的最大立方根 M
        ll M = pow(x, 1.0 / 3.0);
        // 浮点数开方可能存在精度误差，进行微调
        // human: find max M to (M+1)^3 <= x
        while ((M + 1) * (M + 1) * (M + 1) <= x)
            M++;
        while (M * M * M > x)
            M--;

        // 利用单调性，如果 M 增大了，更新完整块的累加和
        // 这里的 current_sum 维护的是所有“完整立方区间”的贡献
        for (ll k = last_x_M; k < M; ++k)
        {
            if (k == 0)
                continue;
            current_sum += k * ((k + 1) * (k + 1) * (k + 1) - k * k * k);
        }

        // 最终答案 = 完整区间总和 + 最后一段不完整区间的贡献
        ll total_sum = current_sum + M * (x - M * M * M + 1);

        cout << total_sum << "\n";

        last_x_M = M;
    }

    return 0;
}