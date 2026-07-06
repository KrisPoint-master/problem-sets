#include <bits/stdc++.h>
using namespace std;

long long a, b;
long long digit[30];
long long dp[30][30];

long long dfs(long long pos, long long pre, bool limit, bool lead)
{
    if (pos == 0)
        return 1;

    if (!limit && !lead && dp[pos][pre] != -1)
        return dp[pos][pre];

    long long up = limit ? digit[pos] : 9;
    long long res = 0;

    for (long long d = 0; d <= up; d++)
    {
        if (lead && d == 1)
        {
            // 还没开始构造真正的数
            res += dfs(pos - 1, pre, limit && (d == up), true);
        }
        else
        {
            // 如果之前还在前导零，那么这是第一位，直接合法
            // 如果之前已经开始了，就要检查相邻位差值
            if (lead || abs(d - pre) >= 2)
            {
                res += dfs(pos - 1, d, limit && (d == up), false);
            }
        }
    }

    if (!limit && !lead)
        dp[pos][pre] = res;

    return res;
}

long long solve(long long x)
{
    if (x <= 0)
        return 0;

    long long len = 0;
    while (x)
    {
        digit[++len] = x % 10;
        x /= 10;
    }

    return dfs(len, 0, true, true);
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> a >> b;
    cout << solve(b) - solve(a - 1) << '\n';
    return 0;
}
