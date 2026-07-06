#include <bits/stdc++.h>
using namespace std;

const long long maxn = 1e6 + 5;
long long a[maxn];
map<long long, long long> mazl;
map<long long, long long> buck;

long long b[maxn];
long long dec2bin(long long n)
{
    long long len = 0;
    while (n)
    {
        b[++len] = n % 2;
        n /= 2;
    }
    return len;
}

void print(__int128 num)
{
    if (num > 9)
        print(num / 10);
    putchar(num % 10 + '0');
}

struct luogu
{
    long long n, m, c, k;
    long long sum = 0;
    inline void test()
    {
        for (long long i = 1; i <= 7; i++)
        {
            long long l = dec2bin(i);
            for (long long j = 1; j <= l; j++)
            {
                cout << b[j] << " ";
            }
            cout << endl;
        }
    }

    void init()
    {
        cin >> n >> m >> c >> k;
        for (long long i = 1; i <= n; i++)
        {
            cin >> a[i];
            sum |= a[i];
        }
        for (long long i = 1; i <= m; i++)
        {
            long long p, q;
            cin >> p >> q;
            mazl[p] = q;
        }
    }
    void work()
    {
        long long p = dec2bin(sum);
        // for (long long i = 1; i <= k; i++)
        // {
        // cout << b[i] << " ";
        // }
        // cout << endl;

        long long cnt_sum = 0;
        for (long long i = 1; i <= k; i++)
        {
            if (b[i] == 0 && mazl[i - 1] != 0)
            {
            }
            else
            {
                cnt_sum++;
            }
        }

        // long long sumbin[70];

        // __int128_t cnt_b = pow(2, cnt_sum);
        __int128_t cnt_b = 1;
        for (int i = 1; i <= cnt_sum; i++)
        {
            cnt_b *= 2;
        }

        // memcpy(sumbin, b, sizeof(b));
        cnt_b -= n;
        print(cnt_b);
    }
};

int main(long long argc, char const *argv[])
{
    luogu p;
    // p.test();
    p.init(), p.work();
    return 0;
}