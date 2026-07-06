#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, k, l) for (int i = j; i <= k; i += l)
const int maxn = 1e3 + 5;

const int mod = 998244353;

int n,
    m, c, f;
int a[maxn][maxn];
int start[maxn][maxn];

int sum[maxn][maxn];

int s(int i, int x)
{
    int tmp = start[i][x];
    int sums = 0;
    for (int y = x + 2; y <= n; y++)
    {
        if (x + 1 < y)
        {
            sums += start[i][y];
        }
    }
    tmp *= sums;
    return tmp;
}

int h(int x)
{
    int temp = 0;
    for (int i = 1; i <= m; i++)
    {
        temp += s(i, x);
    }
    return temp;
}

void work()
{
    // ans = \sum h(i)
    // h(i) = \sum s(i,x)
    // s(i,x) = start(i,x) * \sum(i,y) (x+1<y)
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += h(i) % mod;
    cout << ((ans % mod) * (c % mod)) % mod << endl;
}

int main()
{
    int T, id;
    cin >> T >> id;
    while (T--)
    {
        cin >> n >> m >> c >> f;
        rep(i, 1, n, 1)
        {
            rep(j, 1, m, 1)
            {
                char c;
                cin >> c;
                a[i][j] = c - '0';
                // cout << a[i][j] << " ";
            }
            // cout << endl;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (a[i][j] == 1)
                    start[i][j] = 0;
                else if (a[i][j - 1] == 0)
                {
                    start[i][j] = start[i][j - 1] + 1;
                }
                else
                {
                    start[i][j] = 1;
                }
            }
        }

        // cout << endl;
        // rep(i, 1, n, 1)
        // {
        //     rep(j, 1, m, 1)
        //     {
        //         // start[i][j]++;
        //         // cout << start[i][j] << " ";
        //     }
        //     // cout << endl;
        // }
        // cout << endl;
        memset(sum, 0, sizeof(sum));
        work();
    }
    return 0;
}