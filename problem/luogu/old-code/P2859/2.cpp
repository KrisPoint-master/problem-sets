#include <bits/stdc++.h>
using namespace std;
struct Time
{
    int first, l, r;
} a[50005];
struct stall
{
    int num, last;
};
bool operator<(const stall &a, const stall &b)
{
    return a.last > b.last;
}
bool cmp(Time a, Time b)
{
    return a.l < b.l;
}
priority_queue<stall> q;
int tot, ans[50005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        a[i].first = i;
        cin >> a[i].l;
        cin >> a[i].r;
    }
    sort(a + 1, a + n + 1, cmp);
    stall x;
    x.num = ++tot;
    x.last = a[1].r;
    ans[a[1].first] = 1;
    q.push(x);
    for (int i = 2; i <= n; ++i)
    {
        if (a[i].l <= q.top().last)
        {
            ans[a[i].first] = ++tot;
            x.num = tot;
            x.last = a[i].r;
            q.push(x);
        }
        else
        {
            x = q.top();
            ans[a[i].first] = x.num;
            q.pop();
            x.num = ans[a[i].first];
            x.last = a[i].r;
            q.push(x);
        }
    }
    cout << tot << endl;
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << endl;
    return 0;
}
