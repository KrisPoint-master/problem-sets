#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int64 n, a, d;
        cin >> n >> a >> d;

        int64 lowbit = d & -d;
        int64 ans = (n - 1) * (lowbit - 1);

        cout << ans << '\n';
    }

    return 0;
}