#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
ll a[maxn], b[maxn];
ll n, m, q;
ll l1, r1, l2, r2;
const ll inf = 1e18 + 1;
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
    int l, r;
    bool has_zero = false;
    bool has_neg = false;
    bool has_pos = false;
    ll max_pos = -1;
    ll min_pos = inf;
    ll min_neg = 1;
    ll max_neg = -inf;

    node() {}

    node(ll t)
    {
        if (t > 0)
        {
            has_pos = 1;
            max_pos = min_pos = t;
        }
        if (t < 0)
        {
            has_neg = 1;
            max_neg = min_neg = t;
        }
        if (t == 0)
        {
            has_zero = 1;
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
};
struct sgttree
{
    node tree[maxn * 4];
    void build(int p, int l, int r)
    {
        tree[p].l = l, tree[p].r = r;
        if (l == r)
        {
            tree[p] = node(a[l]);
            return;
        }
        int mid = (l + r) / 2;
        build(2 * p, l, mid);         // 递归建左儿子树
        build(2 * p + 1, mid + 1, r); // 递归建右儿子树
    }

    node merge(node a, node b)
    {
        node c;
        c.has_neg = a.has_neg || b.has_neg;
        c.has_pos = a.has_pos || b.has_pos;
        c.has_zero = a.has_zero || b.has_zero;
        c.max_neg = max(a.max_neg, b.max_neg);
        c.max_pos = max(a.max_pos, b.max_pos);
        c.min_neg = min(a.min_neg, b.min_neg);
        c.min_pos = min(a.min_pos, b.min_pos);
        return c;
    }

    void push_up(int id)
    {
        tree[id] = merge(tree[2 * id], tree[2 * id + 1]);
    }

    node query(int l1, int r1, int l, int r, int rt)
    {
        if (l1 <= l && r <= r1)
        {
            return tree[rt];
        }
        int m = (l + r) >> 1;
        node ret, ret2;
        if (l1 <= m)
            ret = query(l1, r1, l, m, 2 * rt);
        if (r1 > m)
            ret2 = query(l1, r1, m + 1, r, 2 * rt + 1);
        ret = merge(ret, ret2);
        return ret;
    }
};

node each_a(int l, int r, sgttree sgt)
{
    /*
    node t;
    for (int i = l; i <= r; i++)
        t.upd(a[i]);
    return t;
    */
    return sgt.query(l, r, 1, n, 1);
}

int main()
{
    // freopen("in","r",stdin);
    init();
    sgttree sgt;
    sgt.build(1, 1, n);
    while (q--)
    {
        cin >> l1 >> r1 >> l2 >> r2;
        ll b_min = bmin(l2, r2);
        ll b_max = bmax(l2, r2);
        node t = each_a(l1, r1, sgt);
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