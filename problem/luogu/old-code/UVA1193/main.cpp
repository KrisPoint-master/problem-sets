#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

struct q
{
    double l, r;
} c[maxn];

bool cmp(q a, q b)
{
    return a.r < b.r;
}

struct Point
{
    double l;
} p[maxn];
void work(int n, int d, q *c)
{
    int cnt = 0;
    int pointcnty = 0;
    p[++cnt].l = c[1].r;
    pointcnty++;
    for (int i = 2; i <= n; i++)
    {
        for (int j = i; j >= 1; j--)
        {
            if (c[i].l <= p[j].l && c[i].r >= p[j].l)
                goto label_error;
        }
        p[++cnt].l = c[i].r;
        pointcnty++;
    label_error:
        continue;
    }
    cout << pointcnty << endl;
}

int main(int argc, char **argv)
{
    memset(c, 0, sizeof(c));
    int n, d;
    cin >> n >> d;
    if (n == 0 && d == 0)
        return 0;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        if (d * d - y * y < 0)
        {
            cout << "-1" << endl;
            continue;
        }
        int t = sqrt(d * d - y * y);
        c[i].l = x - t;
        c[i].r = x + t;
    }
    sort(c + 1, c + 1 + n, cmp);
    work(n, d, c);
    return 0;
}