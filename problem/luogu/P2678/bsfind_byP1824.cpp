#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;

int l, n, m;
int a[maxn];

int mid(int l, int r)
{
    return (l + r) >> 1; // 这是最快的写法
}

// 检查pos位置的值是否符合要求
bool check(int x)
{
    int tot = 0;
    int i = 0;
    int now = 0;
    while (i < n)
    {
        i++;
        if (a[i] - a[now] < x)
            tot++;
        else
            now = i;
    }
    if (l - a[now] < x)
        tot++;
    return !(tot > m);
}

// bs_find = binary search find
int bs_find(int l, int r)
{
    while (l < r)
    {
        int m = mid(l, r);
        if (check(m))
            l = m + 1;
        else
            r = m;
    }
    return l - 1;
}

int main(int argc, char const *argv[])
{
    cin >> l >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    cout << bs_find(0, l + 1) << endl;

    return 0;
}
