#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int f[10005][1005];

int n, h;
int p[maxn];
int c[maxn];

int main(int argc, char const *argv[])
{
    cin >> n >> h;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= h; j++)
        {
            f[i][j] = f[i - 1][j];
            if (p[i] <= j && f[i][j] > f[i][j - p[i]] + c[i])
                f[i][j] = f[i][j - p[i]] + c[i];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= h; j++)
        {
            cout << f[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
