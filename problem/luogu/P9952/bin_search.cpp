#include <bits/stdc++.h>
using namespace std;

int n;
char a[1000005];

int mid(int l, int r)
{
    return (l + r) >> 1;
}

bool check(int val)
{
}

int bs_find(int l, int r)
{
    while (l < r)
    {
        int m = mid(l, r);
        if (check(m))
            r = m;
        else
            l = m + 1;
    }
    return l;
}

int main(int argc, char const *argv[])
{
    cin >> n >> a;
    int last_pos = 0;
    int d = INT32_MAX;
    for (int i = 1; i <= n; i++)
    {
        int nowa = a[i] - '0';
        if (nowa)
        {
            d = min(d, i - last_pos + 1);
            last_pos = i;
        }
    }

    bs_find(0, d + 1);

    return 0;
}
