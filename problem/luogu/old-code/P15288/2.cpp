#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    if (!(cin >> n >> m))
        return;

    map<int, int> cnt;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        cnt[val]++;
    }

    int g = 0;
    for (auto const &[key, val] : cnt)
    {
        if (g == 0)
            g = val;
        else
            g = __gcd(g, val);
    }

    int L = n / g;
    int ans = 0;

    for (int k = 1; k <= m; k++)
    {
        if (__gcd(n, k) % L == 0)
        {
            ans++;
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}