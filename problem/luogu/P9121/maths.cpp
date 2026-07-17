#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 1e6 + 5;

int n;
ll t, d[maxn], b[maxn];

int main()
{
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i] >> b[i];
    }

    ll stock = 0, ans = 0, prev = 0;

    for (int i = 1; i <= n; i++)
    {
        ll gap = d[i] - prev - 1;
        ll eat = min(stock, gap);
        ans += eat;
        stock -= eat;

        stock += b[i];
        if (stock > 0)
        {
            stock--;
            ans++;
        }

        prev = d[i];
    }

    ll remaining = t - prev;
    ll eat = min(stock, remaining);
    ans += eat;

    cout << ans << endl;

    return 0;
}
