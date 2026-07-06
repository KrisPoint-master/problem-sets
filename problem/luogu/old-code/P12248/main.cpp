#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;

int a[maxn], b[maxn], c[maxn], d[maxn];

int bit[maxn];

void f(int a, int b, int c, int d)
{
    if (c > d)
    {
        bit[a] += 3;
    }
    if (c < d)
    {
        bit[b] += 3;
    }
    if (c == d)
    {
        bit[a]++;
        bit[b]++;
    }
}

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    for (int i = 1; i <= m; i++)
    {
        f(a[i], b[i], c[i], d[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << bit[i] << ' ';
    }

    return 0;
}
