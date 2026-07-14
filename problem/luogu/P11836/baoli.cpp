#include <bits/stdc++.h>
using namespace std;

int n, u;
int mp[2005][2005];

int calc(int x, int y)
{
    int cnt = 0;
    if (mp[n - x + 1][n - y + 1] != mp[x][y])
        cnt++;
    if (mp[n - x + 1][y] != mp[x][y])
        cnt++;
    if (mp[x][n - y + 1] != mp[x][y])
        cnt++;
    return min(cnt, 4 - cnt);
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> u;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char ch;
            cin >> ch;
            mp[i][j] = (ch == '#');
        }
    }
    int sum = 0;
    for (int i = 1; i <= n / 2; i++)
    {
        for (int j = 1; j <= n / 2; j++)
        {
            sum += calc(i, j);
        }
    }
    cout << sum << "\n";
    while (u--)
    {
        int x, y;
        cin >> x >> y;
        int old = calc(x, y);
        mp[x][y] ^= 1;
        int now = calc(x, y);
        sum += (now - old);
        cout << sum << "\n";
    }
}
