#include <bits/stdc++.h>
using namespace std;
int n, a[100005], ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int t = a[n / 2];
    for (int i = 1; i <= n; i++)
    {
        ans += abs(a[i] - t);
    }
    cout << ans;
    return 0;
}
