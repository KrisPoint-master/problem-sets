#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, m, k;
    cin >> n >> m >> k;
    long long ans;
    if (k <= n)
        ans = n * m - k;
    else
        ans = n * (m - 1);
    cout << ans << endl;
    return 0;
}
