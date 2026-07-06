// 在 1.cpp 的基础上使用 线段树来优化
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
ll a[maxn], b[maxn];
ll n, m, q;
ll l1, r1, l2, r2;
const ll inf = 1e18 + 1;

struct node
{
    bool has_zero = false;
    bool has_neg = false;
    bool has_pos = false;
    ll max_pos = -inf; // max(-inf,a) = a;
    ll min_pos = inf;  // min(inf,a) = a;
    ll min_neg = inf;
    ll max_neg = -inf;

    node() {}
    node(ll t)
    {
        if (t == 0)
            has_zero = 1;
        else if (t < 0)
        {
            has_neg = 1;
            // min_neg = max_neg =  t;
            min_neg = max_neg = t;
        }
        else
        {
            has_pos = 1;
            // min_pos = max_pos =  t;
            min_pos = max_pos = t;
        }
    }

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

    // 定义 merge 行为
    friend node operator+(const node &a, const node &b)
    {
        node t;
        t.has_zero = a.has_zero || b.has_zero;
        t.has_neg = a.has_neg || b.has_neg;
        t.has_pos = a.has_pos || b.has_pos;

        t.min_pos = std::min(a.min_pos, b.min_pos);
        t.max_pos = std::max(a.max_pos, b.max_pos);

        t.min_neg = std::min(a.min_neg, b.min_neg);
        t.max_neg = std::max(a.max_neg, b.max_neg);

        return t;
    }
};

template <typename T, int N = maxn>
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

    void build(int l, int r, int p, ll a[])
    {
        if (l == r)
        {
            // scanf("%d",&tr[p]);
            tr[p] = node(a[l]);
            return;
        }
        int m = mid(l, r);
        build(l, m, lp(p), a);
        build(m + 1, r, rp(p), a);
        pushup(p);
    }

    void update(int pos, T v, int l, int r, int p)
    {
        if (l == r)
        {
            tr[p] += v;
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
        T ret1, ret2;
        if (L <= m)
            ret1 = query(L, R, l, m, lp(p));
        if (R >= m + 1)
            ret2 = query(L, R, m + 1, r, rp(p));
        // pushup(p); 因为没有更改，所以不需要
        return ret1 + ret2;
    }
};

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

sgt_point<node> sgt_to_a;
sgt_point<node> sgt_to_b;

node each_a(int l, int r)
{
    node t;
    for (int i = l; i <= r; i++)
        t.upd(a[i]);
    return t;
}

void init()
{
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
        cin >> b[i];

    // 对a数组的sgt进行 init
    sgt_to_a.build(1, n, 1, a);
    sgt_to_b.build(1, m, 1, b);
}

int main()
{
    // freopen("in","r",stdin);
    init();
    while (q--)
    {
        cin >> l1 >> r1 >> l2 >> r2;
        node t = sgt_to_b.query(l2, r2, 1, m, 1);

        ll b_min = t.min_neg;
        if (t.has_zero && t.has_neg == false)
            b_min = 0;
        if (t.has_pos && b_min > t.min_pos)
            b_min = t.min_pos;

        ll b_max = t.max_pos;
        if (t.has_zero && t.has_pos == false)
            b_max = 0;
        if (b_max < t.max_neg)
            b_max = t.max_neg;

        t = sgt_to_a.query(l1, r1, 1, n, 1);
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