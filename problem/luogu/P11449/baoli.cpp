#include <bits/stdc++.h>
using namespace std;

int T;

long long pow10(int e)
{
    long long r = 1;
    while (e--)
        r *= 10;
    return r;
}
// 4 she 5 ru
long long round_to(long long n, int b)
{
    long long base = pow10(b);
    if ((n / pow10(b - 1)) % 10 >= 5)
        n += base;
    return (n / base) * base;
}

int calc_P(long long n)
{
    int P = 0;
    while (pow10(P) < n)
        P++;
    return P;
}

long long old_check(long long n)
{
    int P = calc_P(n);
    return round_to(n, P);
}

long long new_check(long long n)
{
    int P = calc_P(n);
    long long cur = n;
    for (int b = 1; b <= P; b++)
        cur = round_to(cur, b);
    return cur;
}

void work()
{
    long long n;
    cin >> n;
    long long ans = 0;
    for (long long i = 2; i <= n; i++)
    {
        if (old_check(i) != new_check(i))
        {
            ans++;
            cout << "now i:" << i << endl;
        }
        cout << ans << endl;
    }
}

int main()
{
    cin >> T;
    while (T--)
        work();
    return 0;
}
