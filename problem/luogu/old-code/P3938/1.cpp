#include <bits/stdc++.h>
using namespace std;

long long fib[65];
void initfib()
{
    fib[1] = fib[2] = 1;
    for (long long i = 3; i <= 60; i++)
        fib[i] = fib[i - 1] + fib[i - 2];
    // cout << log10(fib[60]) << endl;
}

long long get_father(long long n)
{
    for (long long i = 60; i >= 1; i--)
        if (fib[i] < n)
        {
            n -= fib[i];
            break;
        }
    return n;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    initfib();
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, m;
        cin >> n >> m;
        while (n != m)
        {
            /*
             * 轮流跳
             * 求LCA
             */
            if (n < m)
                swap(n, m);
            n = get_father(n);
        }
        cout << n << endl;
    }
    return 0;
}
