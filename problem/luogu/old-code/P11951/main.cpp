#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[8005], ans;
signed main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int l = j, r = n;
            while (l < r)
            {
                int mid = (l + r + 1) / 2;
                if (a[mid] < a[i] + a[j])
                    l = mid;
                else
                    r = mid - 1;
            }
            ans += l - j;
        }
    }
    cout << ans;
    return 0;
}
