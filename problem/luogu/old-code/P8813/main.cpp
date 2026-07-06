#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    long long a, b;
    long long ans = 1;
    cin >> a >> b;
    if (a == 1)
    {
        cout << 1;
        return 0;
    }
    for (int i = 1; i <= b; i++)
    {
        ans *= a;
        if (ans > (long long)1e9)
        {
            cout << -1;
            return 0;
        }
    }
    cout << ans;
    return 0;
}
