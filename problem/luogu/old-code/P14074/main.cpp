#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Node
{
    ll cnt;
    ll sum;
};

int bit[60];

Node dp[60][60];
bool vis[60][60];

Node dfs(int pos, int parity, bool limit)
{
    if (pos < 0)
    {
        if (parity == 1)
            return {1, 0};
        else
            return {0, 0};
    }

    if (!limit && vis[pos][parity])
        return dp[pos][parity];

    int up = limit ? bit[pos] : 1;

    Node res = {0, 0};

    for (int d = 0; d <= up; d++)
    {
        Node nxt = dfs(pos - 1, parity ^ d, limit && (d == bit[pos]));

        res.cnt += nxt.cnt;

        res.sum += nxt.sum + nxt.cnt * d * (1LL << pos);
    }

    if (!limit)
    {
        vis[pos][parity] = true;
        dp[pos][parity] = res;
    }

    return res;
}

ll solve(ll n)
{
    if (n <= 0)
        return 0;

    int len = 0;

    while (n)
    {
        bit[len++] = n % 2;
        n /= 2;
    }

    Node ans = dfs(len - 1, 0, true);

    return ans.sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll l, r;
    cin >> l >> r;

    cout << solve(r) - solve(l - 1) << '\n';

    return 0;
}