#include <bits/stdc++.h>
using namespace std;

const long long maxn = 5e5 + 5;
long long n;
long long a[maxn], s[maxn];
long long m, f[maxn][25];
struct st
{
    long long log[maxn];
    void pre()
    {
        memset(f, 0, sizeof(f));
        memset(log, 0, sizeof(log));
        for (long long i = 1; i <= n; i++)
            f[i][0] = a[i];
        log[1] = 0, log[2] = 1;
        for (long long i = 3; i <= n; i++)
            log[i] = log[i / 2] + 1;
        for (long long j = 1; j <= log[n]; j++)
        {
            for (long long i = 1; i + (1 << j) - 1 <= n; i++)
            {
                f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
            }
        }
        return;
    }
    long long ask(long long l, long long r)
    {
        long long p = log[r - l + 1];
        return min(f[l][p], f[r - (1 << p) + 1][p]);
    }
} st;

int main(long long argc, char const *argv[])
{
    cin >> n;
    for (long long i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = a[i];
        s[i] += s[i - 1];
    }
    st.pre();
    long long ans = 0;
    for (long long i = 1; i <= n; i++)
    {
        for (long long j = i; j <= n; j++)
        {
            long long mins = st.ask(i, j);
            long long andadd = s[j] - s[i - 1];
            long long m = mins * andadd;
            ans = max(ans, m);
        }
    }

    cout << ans << endl;

    return 0;
}
