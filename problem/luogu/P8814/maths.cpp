#include <bits/stdc++.h>
using namespace std;

int k;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> k;

    while (k--)
    {
        long long n, d, e;
        cin >> n >> d >> e;

        long long m = n - e * d + 2;

        long long delta = m * m - 4 * n;

        if (delta < 0)
        {
            cout << "NO\n";
            continue;
        }

        long long b2 = round(sqrt(delta));

        if (b2 * b2 != delta)
        {
            cout << "NO\n";
            continue;
        }

        long long c1 = m + b2;
        long long c2 = m - b2;

        if (c1 % 2 != 0 || c2 % 2 != 0 || c2 <= 0)
        {
            cout << "NO\n";
            continue;
        }

        long long ll_p = c2 / 2;
        long long q = c1 / 2;

        if (ll_p * q == n)
        {
            cout << min(ll_p, q) << " " << max(ll_p, q) << "\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}