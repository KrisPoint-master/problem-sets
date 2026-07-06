#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 5;
int n;
int a[maxn];
int s[maxn];
int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = a[i];
        s[i] += s[i - 1];
    }
    int cnt = 0;
    for (int k = 1; k <= n; k++)
    {
        int ans = s[n] - s[k + 1 - 1];
        if (ans < 0)
            continue;
        int ans2 = s[k] - s[1 - 1];
        if (ans + ans2 < 0)
            continue;
        cnt++;
    }

    cout << cnt << endl;

    return 0;
}
