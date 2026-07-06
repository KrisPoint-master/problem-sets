#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;

long long n, D;
long long a[maxn];

long long mid(long long l, long long r)
{
    return (l + r) >> 1; // 这是最快的写法
}

long long vis[maxn];
long long flag[maxn];
long long sta[maxn];

// 检查pos位置的值是否符合要求
bool check(long long d)
{
    memset(vis, 0, sizeof vis);
    memset(flag, 0, sizeof flag);
    memset(sta, 0, sizeof sta);
    long long funlevel = 0;
    long long cnt = 0;
    long long cnt_past = 1;
    for (long long day = 1; day <= D; day++)
    {
        for (long long i = cnt_past;
             i <= n, cnt_past <= n;
             i++, cnt_past++)
        {
            if (funlevel >= d)
            {
                flag[day] = 1;
                break;
            }
            if (vis[i])
                continue;
            vis[i] = 1;
            sta[++cnt] = day;
            funlevel += a[i];
        }
        if (funlevel >= d)
        {
            flag[day] = 1;
        }
        funlevel /= 2;
    }
    while (cnt < n)
        sta[++cnt] = D;

    for (long long i = 1; i <= D; i++)
    {
        if (!flag[i])
            return false;
        /* code */
    }

    return true;
}

// bs_find = binary search find answer
long long bs_find(long long l, long long r)
{
    while (l < r)
    {
        long long m = mid(l, r);
        if (check(m))
            l = m + 1;
        else
            r = m;
    }
    return l - 1;
}

int main(int argc, char const *argv[])
{
    cin >> n >> D;
    long long max_r = 0;
    for (long long i = 1; i <= n; i++)
    {
        cin >> a[i];
        max_r += a[i];
    }
    long long ans = bs_find(0, max_r + 1);
    cout << ans << endl;
    check(ans);
    for (long long i = 1; i <= n; i++)
    {
        cout << sta[i] << endl;
    }

    return 0;
}
