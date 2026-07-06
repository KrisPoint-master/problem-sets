#include <bits/stdc++.h>
using namespace std;
int r, a[1010][1010], i, j, dp[1010][1010];

int dfs(int h, int l)
{
    if (dp[h][l] > -1)
        return dp[h][l];
    if (h == r)
        dp[h][l] = a[h][l];
    else
        dp[h][l] = max(dfs(h + 1, l), dfs(h + 1, l + 1)) + a[h][l];
    return dp[h][l];
}
int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> r;
    for (i = 0; i < r; i++)
        for (j = 0; j <= i; j++)
            cin >> a[i][j];

    cout << dfs(0, 0);
    return 0;
}