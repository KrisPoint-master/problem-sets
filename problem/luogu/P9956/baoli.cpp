#include <bits/stdc++.h>
using namespace std;

int n;
int p[1000005];
int s[1000005];
int ans;

int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        s[i] = p[i] + s[i - 1];
    }

    auto get_sum = [](int l, int r) -> int
    {
        return s[r] - s[l - 1];
    };

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (i == j)
            {
                // cout << i << ' ' << j << endl;ws
                ans++;
                continue;
            }
            double av = (get_sum(i, j) * 1.0) / ((j - i + 1) * 1.0);
            for (int k = i; k <= j; k++)
            {
                if (av == p[k] * 1.0)
                    goto succeed;
            }
            continue;
        succeed:
            ans++;
            // cout << i << ' ' << j << endl;
        }
    }
    cout << ans << endl;
    return 0;
}
