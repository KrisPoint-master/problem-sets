#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 5;
typedef long long ll;
int st[maxn << 2];
int flag[maxn << 2];
int cflag[maxn << 2]; // change flag
#define lson(rt) (rt << 1)
#define rson(rt) ((rt << 1) | 1)
int n, m;
void pushup(int rt)
{
    st[rt] = max(st[lson(rt)], st[rson(rt)]);
}
void pushdown(int rt, int m)
{
    if (cflag[rt])
    {
        flag[lson(rt)] = 0;
        flag[rson(rt)] = 0;
        cflag[lson(rt)] = cflag[rson(rt)] = cflag[rt];
        cflag[rt] = 0;
    }
    if (flag[rt])
    {
        flag[lson(rt)] = flag[rt];
        flag[rson(rt)] = flag[rt];
        st[lson(rt)] = flag[rt] * (m - (m >> 1));
        st[rson(rt)] = flag[rt] * (m >> 1);
        flag[rt] = 0;
    }
}
void update(int l1, int r1, int c, int l, int r, int rt)
{
    if (l1 <= l && r <= r1)
    {
        flag[rt] = c; // 我们到达一个点
        st[rt] = (r - l + 1) * c;
        return;
    }
    pushdown(rt, (r - l + 1));
    int m = (l + r) >> 1;
    if (l1 <= m)
        update(l1, r1, c, l, m, lson(rt));
    if (r1 > m)
        update(l1, r1, c, m + 1, r, rson(rt));
    pushup(rt);
}
int query(int l1, int r1, int l, int r, int rt)
{
    if (l1 <= l && r <= r1)
    { // 包含
        return st[rt];
    }

    // 路过
    pushdown(rt, (r - l + 1));
    int ret = 0;
    int m = (l + r) >> 1;
    if (l1 <= m)
        ret = max(ret, query(l1, r1, l, m, lson(rt)));
    if (r1 > m)
        ret = max(ret, query(l1, r1, m + 1, r, rson(rt)));
    return ret;
}
void build(int l, int r, int rt)
{
    if (l == r)
    {
        scanf("%d", &st[rt]);
        return;
    }
    int m = (l + r) >> 1;
    build(l, m, lson(rt));
    build(m + 1, r, rson(rt));
    pushup(rt);
}

int main()
{
    ll n, m;
    cin >> n >> m;
    build(1, n, 1);
    while (m--)
    {
        int how;
        cin >> how;
        if (how == 1)
        {
            ll x, y, k;
            cin >> x >> y >> k;
            update(x, y, k, 1, n, 1);
        }
        else if (how == 2)
        {
            ll x, y, k;
            cin >> x >> y >> k;
            update(x, y, k + query(x, y, 1, n, 1), 1, n, 1);
        }
        else if (how == 3)
        {
            ll x, y;
            cin >> x >> y;
            cout << query(x, y, 1, 1, n) << endl;
        }
    }

    return 0;
}
