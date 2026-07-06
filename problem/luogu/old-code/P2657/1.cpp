#include <bits/stdc++.h>
using namespace std;

int a, b;
int bg[15];
int dp[15][15];
int dfs(int pos, int pre, bool limit, bool lead)
{
    if (pos == 0)
    {
        return lead ? 0 : 1;
    }
    if (!limit && !lead && dp[pos][pre] != -1)
        return dp[pos][pre];

    int r = 9;
    if (limit)
    {
        r = bg[pos];
    }
    int res = 0;
    for (int i = 0; i <= r; i++)
    {
        if (lead && i == 0)
        {
            res += dfs(pos - 1, pre, limit && (i == r), true);
        }
        else
        {
            if (lead || abs(i - pre) >= 2)
            {
                res += dfs(pos - 1, i, limit && (i == r), false);
            }
        }
    }
    if (!lead && !limit)
    {
        dp[pos][pre] = res;
    }
    return res;
}

int solve(int x)
{
    if (x <= 0)
        return 0;
    int len = 0;
    while (x)
    {
        bg[++len] = x % 10;
        x /= 10;
    }

    return dfs(len, 0, 1, 1);
}

int main(int argc, char const *argv[])
{
    memset(dp, -1, sizeof(dp));
    cin >> a >> b;
    cout << solve(b) - solve(a - 1) << '\n';
    return 0;
}
