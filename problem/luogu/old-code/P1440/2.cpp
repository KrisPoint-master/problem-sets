#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e6 + 5;
int n, m, f[maxn][50];
long long a[maxn];
struct st
{
    int log[maxn];
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

int main()
{
    memset(a, 0x3f, sizeof(a));
    cin >> n >> m;
    for (long long i = m; i <= n + m - 1; i++)
    {
        cin >> a[i];
    }

    st.pre();
    for (long long i = m; i <= n + m - 1; i++)
    {
        long long ans = st.ask(i - m, i - 1);
        if (ans == 0x3f3f3f3f)
        {
            cout << 0 << endl;
            continue;
        }
        cout << ans << endl;
    }

    return 0;
}