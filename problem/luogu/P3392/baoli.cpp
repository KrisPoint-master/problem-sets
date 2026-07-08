#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 55;
int n, m;
char a[maxn][maxn];

signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int ans = n * m;
    for (int i = 2; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int sum = 0;
            for (int x = 1; x < i; x++)
                for (int y = 0; y < m; y++)
                    if (a[x][y] != 'W')
                        ++sum;
            for (int x = i; x < j; x++)
                for (int y = 0; y < m; y++)
                    if (a[x][y] != 'B')
                        ++sum;
            for (int x = j; x <= n; x++)
                for (int y = 0; y < m; y++)
                    if (a[x][y] != 'R')
                        ++sum;
            if (sum < ans)
                ans = sum;
        }
    }
    printf("%d", ans);
    return 0;
}
