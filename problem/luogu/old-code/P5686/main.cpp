#include <bits/stdc++.h>
using namespace std;

long long a[1000005];
long long b[1000005];

const long long mod = 1e9 + 5;

long long suml(long long l, long long r, long long *a, long long *b)
{
    long long sum = 0, s = 0;
    for (long long i = l; i <= r; i++)
    {
        sum += a[i] % mod;
    }
    for (long long i = l; i <= r; i++)
    {
        s += b[i] % mod;
    }

    return ((sum % mod) * (s % mod)) % mod;
}

int main(long long argc, char const *argv[])
{
    long long n;
    cin >> n;
    for (long long i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (long long i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    long long sum = 0;
    for (long long l = 1; l <= n; l++)
    {
        for (long long r = l; r <= n; r++)
        {
            sum += suml(l, r, a, b) % mod;
        }
    }
    cout << sum % mod << endl;

    return 0;
}
