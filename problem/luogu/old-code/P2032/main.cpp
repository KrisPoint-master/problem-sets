#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 5;

#ifndef ONLINE_JUDGE
void print_array(int a[], int start = 1, int end = maxn - 5)
{
    for (int i = start; i <= end; i++)
        printf("a%X[%d]=%d\n", &a, i, a[i]);
}
#else
void print_array(int a[], int start = 1, int end = maxn - 5) {}
#endif

struct luogu
{
    int n, k;
    int a[maxn];
    int f[maxn][50];
    int log[maxn];
    void init()
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        print_array(a, 1, n);
    }
    void pre()
    {
        memset(f, 0, sizeof(f));
        memset(log, 0, sizeof(log));
        for (int i = 1; i <= n; i++)
            f[i][0] = a[i];
        log[1] = 0, log[2] = 1;
        for (int i = 3; i <= n; i++)
            log[i] = log[i / 2] + 1; // 注意是从3开始
        for (int j = 1; j <= log[n]; j++)
        {
            for (int i = 1; i + (1 << j) - 1 <= n; i++)
            {
                f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
            }
        }
        return;
    }
    void pre2()
    {
        memset(f, 0, sizeof(f));
        memset(log, 0, sizeof(log));
        for (int i = 1; i <= n; i++)
            f[i][0] = a[i];
        log[1] = 0, log[2] = 1;
        for (int i = 3; i <= n; i++)
            log[i] = log[i / 2] + 1; // 注意是从3开始
        for (int j = 1; j <= log[n]; j++)
        {
            for (int i = 1; i + (1 << j) - 1 <= n; i++)
            {
                f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
            }
        }
        return;
    }

    int ask(int l, int r)
    {
        int p = log[r - l + 1];
        return max(f[l][p], f[r - (1 << p) + 1][p]);
    }

    int ask2(int l, int r)
    {
        int p = log[r - l + 1];
        return min(f[l][p], f[r - (1 << p) + 1][p]);
    }

    void work()
    {
        pre();
        for (int i = 1; i <= n - k + 1; i++)
        {
            int maxx = ask(i, k + i - 1);
            cout << maxx << endl;
        }
    }

    void output()
    {
    }
} run;

int main(int argc, char const *argv[])
{
    run.init();
    run.work();
    run.output();
    return 0;
}
