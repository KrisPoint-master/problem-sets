#include <bits/stdc++.h>
using namespace std;
const int mod = 10007, Mod = 1e9 + 7;
int n, m, cnt, ans[100001];
long long a[102], A[102];
bool vis[mod];

bool f(int x0, int M, long long *t)
{
    long long res = t[n];
    for (int i = n - 1; i >= 0; i--)
        res = (res * x0 + t[i]) % M;
    return res == 0;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; i++)
    {
        long long x = 0, X = 0;
        bool F = false;
        char c = getchar();
        while (c < '0' || '9' < c)
        {
            if (c == '-')
                F = true;
            c = getchar();
        }
        while ('0' <= c && c <= '9')
        {
            x = (x << 3) + (x << 1) + c - '0', X = (X << 3) + (X << 1) + c - '0';
            x %= mod, X %= Mod;
            c = getchar();
        }
        a[i] = F ? mod - x : x, A[i] = F ? Mod - X : X;
    }
    for (int i = 0; i < mod; i++)
        if (f(i, mod, a))
            vis[i] = true;
    for (int i = 1; i <= m; i++)
        if (vis[i % mod] && f(i, Mod, A))
            ans[++cnt] = i;
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; i++)
        printf("%d\n", ans[i]);
    return 0;
}
