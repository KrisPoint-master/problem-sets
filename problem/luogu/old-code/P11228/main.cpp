#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;

int n, m, k;
int a[maxn][maxn];
bool vis[maxn][maxn];

pair<int, int> next_pos(int x, int y, int d)
{
    switch (d)
    {
    case 0:
        y++;
        break;
    case 1:
        x++;
        break;
    case 2:
        y--;
        break;
    case 3:
        x--;
        break;

    default:
        break;
    }
    return make_pair(x, y);
}

bool check(pair<int, int> pos, int d, int n, int m)
{
    if (1 <= pos.first && pos.first <= n && 1 <= pos.second &&
        pos.second <= m && a[pos.first][pos.second])
        return true;
    return false;
}

void update(pair<int, int> pos, int *x, int *y)
{
    *x = pos.first;
    *y = pos.second;
}

void reset()
{
    n = m = k = 0;
    memset(a, 0, sizeof(a));
    memset(vis, 0, sizeof(vis));
}

int main(int argc, char **argv)
{
    int T;
    cin >> T;
    while (T--)
    {
        int x, y, d;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                char c;
                cin >> c;
                if (c == '.')
                    a[i][j] = 1;
                else
                    a[i][j] = 0;
            }
        }

        for (int i = 1; i <= k; i++)
        {
            vis[x][y] = 1;
            pair<int, int> p = next_pos(x, y, d);
            bool blc = check(p, d, n, m);
            if (blc)
            {
                update(p, &x, &y);
                vis[x][y] = 1;
            }
            else
            {
                d = (d + 1) % 4;
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                // cout << vis[i][j] << " ";
                if (vis[i][j])
                    ans++;
            }
            // cout << endl;
        }
        cout << ans << endl;
        reset();
    }

    return 0;
}