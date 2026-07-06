#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;

int a[maxn];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    int cnt = 0;
    for (int k = 1; k <= n; ++k)
    {
        int m = 0;
        bool v = 1;
        for (int i = k + 1; i <= n; ++i)
        {
            m += a[i];
            if (m < 0)
            {
                goto end;
            }
        }
        for (int i = 1; i <= k; ++i)
        {
            m += a[i];
            if (m < 0)
            {
                goto end;
            }
        }

        if (v)
        {
            cnt++;
            continue;
        }

    end:
        continue;
    }

    cout << cnt << endl;
    return 0;
}
