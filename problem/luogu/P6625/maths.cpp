#include <bits/stdc++.h>
using namespace std;

long long n;
long long a[10000005];

int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    long long ans = 0;

    for (int i = 2; i <= n; i++)
    {
        if (a[i] > 0)
            ans += a[i];
    }

    cout << ans << endl;

    return 0;
}
