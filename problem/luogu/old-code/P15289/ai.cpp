#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1000005;
int n, a, d, x, y, b[N];
// x：先向右再向左的最优解，y：先向左再向右的最优解。
signed main()
{
    cin >> n >> a >> d;
    --n;
    // 因为是 n-1 对怪兽，--n 更方便计算
    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i];
        b[i] = max(0ll, (b[i] - 2) / (2 * d));
    }
    // 预处理 c[i]，即每格最多能进行多少回合，直接覆盖在 b[i] 上即可。
    for (int i = a; i <= n; ++i)
    {
        if (!b[i] && (b[i - 1] < 2 || b[i + 1] < 2))
            break;
        // 向左走如果当前格为 0，左右两个至少有一个 <=2，就掉头。
        x += b[i];
    }
    for (int i = a - 1; i >= 1; --i)
    {
        if (!b[i] && !b[i - 1])
            break;
        // 向右走如果连续两格为 0，就停止。
        x += b[i];
    }
    // 计算向左走最优解
    for (int i = a; i >= 1; --i)
    {
        if (!b[i] && (b[i - 1] < 2 || b[i + 1] < 2))
            break;
        y += b[i];
    }
    for (int i = a + 1; i <= n; ++i)
    {
        if (!b[i] && !b[i + 1])
            break;
        y += b[i];
    }
    // 计算向右走最优解同理
    cout << max(x, y) << "\n";
    // 左右两种方式取最大值输出
    return 0;
}
// 实际代码行数=总代码函数-注释代码行数=36-9=27行
