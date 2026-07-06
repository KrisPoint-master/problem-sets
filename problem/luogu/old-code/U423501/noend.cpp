#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e6 + 5;
const int mod = 10007;

int n, m, k;
int a[maxn];
int target[maxn];

struct machine
{
    int i = 0;
    int o;
    long long x, y;

    void run_task();
} mach[maxn];
string s;
void machine::run_task()
{
    if (o == 1)
    {
        target[x] += y;
        target[x] %= mod;
    }

    if (o == 2)
        for (int i = x; i <= y; i++)
            mach[i].run_task();
}

void init()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        mach[i].i = i;
        cin >> mach[i].o >> mach[i].x >> mach[i].y;
    }
}

int cf[maxn];

void add_cf(int l, int r, int v)
{
    cf[l] += v;
    cf[r + 1] -= v;
}
void sub_cf(int l, int r, int v)
{
    cf[l] -= v;
    cf[r + 1] += v;
}

void work()
{
    // reverse(a + 1, a + 1 + n);
    for (int i = 1; i <= k; i++)
    {
        add_cf(a[i], a[i], 1);
    }

    for (int i = n; i >= 1; i--)
    {
        if (cf[i] == 1)
        {
            sub_cf(i, i, 1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    work();

    return 0;
}
