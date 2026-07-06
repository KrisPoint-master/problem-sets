#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
typedef long long ll;

int n, V;
int a[1005][1005]; // 地图
// 普通gcd
int gcd(int a, int b)
{
    return (b == 0) ? a : gcd(b, a % b);
}

// 检查有没有超出边界
bool check(int nowi, int nowj)
{
    if (nowi < 1 || nowi > n)
        return 0;
    if (nowj < 1 || nowj > n)
        return 0;
    return 1;
}

set<int> vis[1005][1005];
int maxans = -1;
void dfs(int nowi, int nowj, int nowv)
{
    if (!check(nowi, nowj))
        return;
    // 记忆化核心 根据不同路径加入set
    if (vis[nowi][nowj].count(nowv))
        return;
    vis[nowi][nowj].insert(nowv);
    // 边界处理
    if (nowi == n && nowj == n)
    {
        maxans = max(maxans, nowv);
        return;
    }

    dfs(nowi + 1, nowj, gcd(nowv, a[nowi + 1][nowj]));
    dfs(nowi, nowj + 1, gcd(nowv, a[nowi][nowj + 1]));
}

signed main(int argc, const char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> V;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    dfs(1, 1, a[1][1]);

    cout << maxans << endl;
    // END
    return 0;
}