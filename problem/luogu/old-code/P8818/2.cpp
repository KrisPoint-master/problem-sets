#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int a[maxn];
int b[maxn];
int n, m, q;

void read(int *a, int n, int flag = 0)
{
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
}

void init()
{
    cin >> n >> m >> q;
    read(a, n, 1);
    read(b, m, 0);
}

void work()
{
    int l1, r1, l2, r2;
    while (q--)
    {
        cin >> l1 >> r1 >> l2 >> r2;
        int amax1, amax2, amin2, amin1; // 1为正数，2为负数
        int bmax1, bmax2, bmin1, bmin2;
        amax1 = amax2 = bmax1 = bmax2 = INT32_MIN;
        amin2 = amin1 = bmin2 = bmin1 = INT32_MAX;
        for (int i = l1; i <= r1; i++)
        {
            if (a[i] > 0)
            {
                amax1 = max(amax1, a[i]);
                amin1 = min(amin1, a[i]);
            }
            if (a[i] < 0)
            {
                amax2 = max(amax2, a[i]);
                amin2 = min(amin2, a[i]);
            }
        }
        for (int j = l2; j <= r2; j++)
        {
            if (b[j] > 0)
            {
                bmax1 = max(bmax1, b[j]);
                bmin1 = min(bmin1, b[j]);
            }
            if (b[j] < 0)
            {
                bmax2 = max(bmax2, b[j]);
                bmin2 = min(bmin2, b[j]);
            }
        }
        if (bmax2 == INT32_MIN)
        {
            cout << bmin1 * amax1 << endl;
            continue;
        }
        if (bmin1 = INT32_MAX)
        {
            cout << amin2 * bmin1 << endl;
            continue;
        }
        }
}

int main(int argc, char **argv)
{
    init(), work();
    return 0;
}