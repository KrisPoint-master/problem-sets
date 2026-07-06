#include <bits/stdc++.h>
using namespace std;

// digit[pos] : 存储上界 x 的每一位数字
// 这里采用“低位在前”的存法
// 比如 x = 325，则：
// digit[1] = 5
// digit[2] = 2
// digit[3] = 3
int digit[15];

// dp[pos][pre] 表示：
// 在“不受上界限制”且“已经开始构造数字（没有前导零问题）”的情况下，
// 当前还剩 pos 位要填，且上一位数字是 pre 时，合法方案数是多少。
//
// 为什么只需要这两个维度？
// 因为当 limit = false 且 lead = false 时：
// 后面的决策只与“还剩多少位”和“上一位是什么”有关。
int dp[15][10];

int a, b;

/*
dfs(pos, pre, limit, lead)

含义：
- 当前正在处理第 pos 位
- pre表示上一位填的真实数字
- limit 表示当前是否受到上界限制
    true  -> 当前位最大只能填到 digit[pos]
    false -> 当前位可以随便填 0~9
- lead 表示前面是否全是前导零
    true  -> 到目前为止还没有出现过非零数字
    false -> 前面已经出现过真实数字了

返回值：
- 从当前状态出发，能构造出的合法 Windy 数个数
*/
int dfs(int pos, int pre, bool limit, bool lead)
{
    // 递归边界：
    // 当 pos == 0，说明所有位都已经处理完了，
    // 当前构造出了一种完整方案，因此返回 1
    if (pos == 0)
        return 1;

    // 记忆化：
    // 只有在“不受上界限制”并且“已经开始构造数字”时，
    // 这个状态才可以稳定复用
    if (!limit && !lead && dp[pos][pre] != -1)
        return dp[pos][pre];
    // 当前位能填的上限
    // 如果受上界限制，则最多填到 digit[pos]
    // 否则最多填到 9
    int up = limit ? digit[pos] : 9;

    // 记录当前状态的答案
    int res = 0;

    // 枚举当前位填什么数字 d
    for (int d = 0; d <= up; d++)
    {

        // 情况1：当前仍处于前导零阶段，并且这一位继续填 0
        // 例如在枚举 5 位数时，00037 前面的 0 都属于前导零
        // 前导零不算真正的数字，因此：
        // 1. 不需要检查和 pre 的差值
        // 2. 下一层仍然是 lead = true
        if (lead && d == 0)
        {
            res += dfs(
                pos - 1,
                pre,                // pre 这里无意义，保留即可
                limit && (d == up), // 是否继续贴着上界
                true                // 仍然处于前导零状态
            );
        }
        else
        {
            // 情况2：不再是“前导零继续”
            // 分两种子情况：

            // 2.1 如果之前还在前导零（lead == true），
            //     那么当前这个 d 是“第一个非零数字”
            //     第一位没有相邻位，因此一定合法

            // 2.2 如果之前已经开始构造数字（lead == false），
            //     那么当前位 d 必须满足：
            //     abs(d - pre) >= 2
            //
            // 所以这里统一写成：
            // 如果 lead == true（说明这是第一位真实数字） -> 直接合法
            // 否则必须检查 abs(d - pre) >= 2
            if (lead || abs(d - pre) >= 2)
            {
                res += dfs(
                    pos - 1,
                    d,                  // 当前位填了 d，下一层的上一位就是 d
                    limit && (d == up), // 是否继续受上界限制
                    false               // 已经出现了真实数字，不再是前导零
                );
            }
        }
    }

    // 记忆化存储
    // 同样，只有在 !limit && !lead 时才能存
    if (!limit && !lead)
        dp[pos][pre] = res;

    return res;
}

/*
solve(x)：
计算 [0, x] 中有多少个 Windy 数
*/
int solve(int x)
{
    // 如果 x <= 0，那么区间 [0, x] 中没有正整数 Windy 数
    // 直接返回 0
    if (x <= 0)
        return 0;

    // 拆位
    int len = 0;
    while (x)
    {
        digit[++len] = x % 10;
        x /= 10;
    }

    // 从最高位开始搜索：
    // pos = len         -> 当前处理最高位
    // pre = 0           -> 一开始没有上一位，这里随便给个占位值
    // limit = true      -> 一开始必须贴着上界
    // lead = true       -> 一开始还没有填任何真实数字
    return dfs(len, 0, true, true);
}

int main()
{
    // 初始化记忆化数组为 -1，表示“还没算过”
    memset(dp, -1, sizeof(dp));

    // 输入区间 [a, b]
    cin >> a >> b;

    // 区间统计套路：
    // [a, b] = [0, b] - [0, a-1]
    cout << solve(b) - solve(a - 1) << '\n';

    return 0;
}