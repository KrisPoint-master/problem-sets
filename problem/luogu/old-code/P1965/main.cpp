#include <bits/stdc++.h>
using namespace std;

long long binpow(long long a, long long b, long long p)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}
int main(int argc, char const *argv[])
{

    long long n, m, k, x;
    cin >> n >> m >> k >> x;
    long long sum1 = x % n;
    long long sum2 = static_cast<long long>(binpow(10, k, n)) % n;
    long long sum3 = m % n;
    long long sum4 = (sum2 * sum3) % n;
    long long ans = (sum1 % n + sum4 % n) % n;
    cout
        << ans << endl;
    return 0;
}