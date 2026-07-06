#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
ll a[maxn], b[maxn];
ll n, m, q;
ll l1, r1, l2, r2;
const ll inf = 1e18 + 1;

namespace SegTree
{
    template <typename T, int N = 100005>
    struct sgt_point
    {
        T tr[N * 4 + 5];
        inline int lp(int p) { return p << 1; }
        inline int rp(int p) { return (p << 1) | 1; }
        inline int mid(int l, int r) { return (l + r) >> 1; }

        inline void pushup(int p)
        {
            tr[p] = tr[lp(p)] + tr[rp(p)];
        }

        void build(int l, int r, int p)
        {
            if (l == r)
            {
                scanf("%d", &tr[p]);
                return;
            }
            int m = mid(l, r);
            build(l, m, lp(p));
            build(m + 1, r, rp(p));
            pushup(p);
        }

        void update(int pos, T v, int l, int r, int p)
        {
            if (l == r)
            {
                tr[p] = v;
                return;
            }
            int m = mid(l, r);
            if (pos <= m)
                update(pos, v, l, m, lp(p));
            else
                update(pos, v, m + 1, r, rp(p));
            pushup(p);
        }

        T query(int L, int R, int l, int r, int p)
        {
            if (L <= l && r <= R)
            {
                return tr[p];
            }
            int m = mid(l, r);
            T ret = 0;
            if (L <= m)
                ret += query(L, R, l, m, lp(p));
            if (R >= m + 1)
                ret += query(L, R, m + 1, r, rp(p));
            // pushup(p); 因为没有更改，所以不需要
            return ret;
        }
    };
    template <typename T, int N = 100005>
    struct sgt_max
    {
        T tr[N * 4 + 5];
        inline int lp(int p) { return p << 1; }
        inline int rp(int p) { return (p << 1) | 1; }
        inline int mid(int l, int r) { return (l + r) >> 1; }

        inline void pushup(int p)
        {
            tr[p] = max(tr[lp(p)], tr[rp(p)]);
        }

        void build(int l, int r, int p, int *a)
        {
            if (l == r)
            {
                tr[p] = a[l];
                return;
            }
            int m = mid(l, r);
            build(l, m, lp(p));
            build(m + 1, r, rp(p));
            pushup(p);
        }

        void update(int pos, T v, int l, int r, int p)
        {
            if (l == r)
            {
                tr[p] = v;
                return;
            }
            int m = mid(l, r);
            if (pos <= m)
                update(pos, v, l, m, lp(p));
            else
                update(pos, v, m + 1, r, rp(p));
            pushup(p);
        }

        T query(int L, int R, int l, int r, int p)
        {
            if (L <= l && r <= R)
            {
                return tr[p];
            }
            int m = mid(l, r);
            T ret = 0;
            if (L <= m)
                ret = max(ret, query(L, R, l, m, lp(p)));
            if (R >= m + 1)
                ret = max(query(L, R, m + 1, r, rp(p)), ret);
            // pushup(p); 因为没有更改，所以不需要
            return ret;
        }
    };
    template <typename T, int N = 100005>
    struct sgt_min
    {
        T tr[N * 4 + 5];
        inline int lp(int p) { return p << 1; }
        inline int rp(int p) { return (p << 1) | 1; }
        inline int mid(int l, int r) { return (l + r) >> 1; }

        inline void pushup(int p)
        {
            tr[p] = min(tr[lp(p)], tr[rp(p)]);
        }

        void build(int l, int r, int p, int *a)
        {
            if (l == r)
            {
                tr[p] = a[l];
                return;
            }
            int m = mid(l, r);
            build(l, m, lp(p));
            build(m + 1, r, rp(p));
            pushup(p);
        }

        void update(int pos, T v, int l, int r, int p)
        {
            if (l == r)
            {
                tr[p] = v;
                return;
            }
            int m = mid(l, r);
            if (pos <= m)
                update(pos, v, l, m, lp(p));
            else
                update(pos, v, m + 1, r, rp(p));
            pushup(p);
        }

        T query(int L, int R, int l, int r, int p)
        {
            if (L <= l && r <= R)
            {
                return tr[p];
            }
            int m = mid(l, r);
            T ret = 0;
            if (L <= m)
                ret = min(ret, query(L, R, l, m, lp(p)));
            if (R >= m + 1)
                ret = min(query(L, R, m + 1, r, rp(p)), ret);
            // pushup(p); 因为没有更改，所以不需要
            return ret;
        }
    };
};

void init()
{
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
}

ll bmin(ll l, ll r)
{
    ll res = b[l];
    for (int i = l + 1; i <= r; i++)
        if (res > b[i])
            res = b[i];
    return res;
}

ll bmax(ll l, ll r)
{
    ll res = b[l];
    for (int i = l + 1; i <= r; i++)
        if (res < b[i])
            res = b[i];
    return res;
}

struct node
{
    bool has_zero = false;
    bool has_neg = false;
    bool has_pos = false;
    ll max_pos = -1;
    ll min_pos = inf;
    ll min_neg = 1;
    ll max_neg = -inf;

    void upd(ll t)
    {
        if (t == 0)
            has_zero = 1;
        else if (t < 0)
        {
            has_neg = 1;
            max_neg = std::max(max_neg, t);
            min_neg = std::min(min_neg, t);
        }
        else
        {
            has_pos = 1;
            max_pos = std::max(max_pos, t);
            min_pos = std::min(min_pos, t);
        }
    }
};

node each_a(int l, int r)
{
    node t;
    for (int i = l; i <= r; i++)
        t.upd(a[i]);
    return t;
}

int main()
{
    // freopen("in","r",stdin);
    init();
    while (q--)
    {
        cin >> l1 >> r1 >> l2 >> r2;
        ll b_min = bmin(l2, r2);
        ll b_max = bmax(l2, r2);
        node t = each_a(l1, r1);
        ll ans = -inf;
        if (t.has_zero)
            ans = 0;
        if (t.has_neg)
        {
            ans = std::max(ans, b_max * t.max_neg);
            ans = std::max(ans, b_max * t.min_neg);
        }

        if (t.has_pos)
        {
            ans = std::max(ans, b_min * t.max_pos);
            ans = std::max(ans, b_min * t.min_pos);
        }
        cout << ans << endl;
    }

    return 0;
}