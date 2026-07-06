#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;

int n, m;
int a[maxn];

int mid(int l, int r)
{
    return (l + r) >> 1; // 这是最快的写法
}

// 检查pos位置的值是否符合要求
bool check(int d)
{
    int cnt = 1;
    int last = a[1];

    for (int i = 2; i <= n; i++)
    {
        if (a[i] - last >= d)
        {
            cnt++;
            last = a[i];
        }

        if (cnt >= m)
        {
            return true;
        }
    }

    return false;
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
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    sort(a + 1, a + 1 + n);

    cout << bs_find(0, a[n] - a[1] + 1) << endl;

    return 0;
}
