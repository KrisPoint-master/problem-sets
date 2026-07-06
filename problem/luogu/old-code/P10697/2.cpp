#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll dp[25][20];
int num[25];

ll n;
int x;

ll dfs(int pos, int last, bool limit, bool lead)
{
    if (pos == 0)
        return 1;

    if (!limit && dp[pos][last] != -1)
        return dp[pos][last];

    int up = limit ? num[pos] : 9;

    ll res = 0;

    for (int i = 0; i <= up; i++)
    {
        if (i == x)
            continue;

        res += dfs(pos - 1, i,
                   limit && i == num[pos],
                   lead && i == 0);
    }

    if (!limit)
        dp[pos][last] = res;

    return res;
}

ll solve(ll val)
{
    int len = 0;

    if (val == 0)
    {
        num[++len] = 0;
    }
    else
    {
        while (val)
        {
            num[++len] = val % 10;
            val /= 10;
        }
    }

    memset(dp, -1, sizeof(dp));

    return dfs(len, 0, true, true);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        cin >> n >> x;

        cout << solve(n) << '\n';
    }

    return 0;
}