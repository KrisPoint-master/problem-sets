#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int d[maxn];
int a[maxn];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        d[i] = a[i] - a[i - 1];
    }

    int ans = 0;
    int ans2 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (d[i] > 0)
        {
            ans += d[i];
        }
        if (d[i] < 0)
        {
            ans2 += abs(d[i]);
        }
    }
    cout << max(ans, ans2);
    return 0;
}
