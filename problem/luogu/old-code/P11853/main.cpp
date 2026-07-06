#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;

int a[maxn];

int main(int argc, char **argv)
{
    // fw shangdong csp-j2022
    int n;
    cin >> n;

    int cnt = INT32_MIN;

    for (int i = 1; i <= n; i++)
    {
        int al, bl;
        cin >> al >> bl;
        a[al]++;
        a[bl + 1]--;
        cnt = max(bl + 1, cnt);
    }

    int ans = INT32_MIN;

    for (int i = 0; i <= cnt; i++)
    {
        a[i] += a[i - 1];
        ans = max(a[i], ans);
    }

    cout << ans << endl;

    return 0;
}