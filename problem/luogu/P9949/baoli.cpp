#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 105;
int n;
int x[maxn], y[maxn];

void init()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
    }
}

signed main()
{
    init();
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j || y[i] != y[j])
                continue;
            for (int k = 1; k <= n; k++)
            {
                if (i == k || j == k || x[i] != x[k])
                    continue;
                int cur = abs(x[j] - x[i]) * abs(y[k] - y[i]);
                if (cur > ans)
                    ans = cur;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
