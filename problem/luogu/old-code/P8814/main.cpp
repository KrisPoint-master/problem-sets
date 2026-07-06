#include <bits/stdc++.h>
using namespace std;

int main(int argc, const char *argv[])
{
    long long k;
    cin >> k;
    while (k--)
    {
        long long n, e, d;
        cin >> n >> e >> d;
        long long l = sqrt((n - e * d + 2) * (n - e * d + 2) - (n * 4));
        long long j = n - e * d + 2;
        long long P = (l + j) / 2;
        long long Q = j - P;
        if (P * Q == n && e * d == (P - 1) * (Q - 1) + 1 && P && Q)
        {
            printf("%lld %lld\n", min(P, Q), max(P, Q));
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
