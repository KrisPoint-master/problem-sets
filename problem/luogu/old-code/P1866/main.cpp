#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int main(int argc, char const *argv[])
{
    int n, a[666] = {0};
    long long ans = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    for (int i = 0; i < n; i++)
    {
        ans *= (a[i] - i);
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
