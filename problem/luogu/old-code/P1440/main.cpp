#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 2e7 + 5;

long long n, m;
long long a[maxn];
long long l = 1, r = 0, ans = INT32_MAX;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (ans == INT32_MAX)
            cout << 0 << endl;
        else
            cout << ans << endl;

        if (a[i] < ans)
            ans = a[i];
        else if (r - l + 1 >= m && ans == a[l])
        {
            ans = INT32_MAX;
            for (int j = l + 1; j <= r + 1; j++)
                if (ans > a[j])
                    ans = a[j];
        }
        if (r - l + 1 >= m)
            l++;
        r++;
    }

    return 0;
}
