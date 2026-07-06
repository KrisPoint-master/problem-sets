#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int INF = 1e9;

int n, l, r;
int a[MAXN];

struct SegmentTree
{
    int tree[MAXN << 2];

    void pushup(int rt)
    {
        tree[rt] = max(tree[rt << 1], tree[rt << 1 | 1]);
    }

    void build(int l, int r, int rt)
    {
        tree[rt] = -INF; // 初始化为极小值
        if (l == r)
            return;
        int mid = (l + r) >> 1;
        build(l, mid, rt << 1);
        build(mid + 1, r, rt << 1 | 1);
    }

    void update(int idx, int val, int l, int r, int rt)
    {
        if (l == r)
        {
            tree[rt] = val;
            return;
        }
        int mid = (l + r) >> 1;
        if (idx <= mid)
            update(idx, val, l, mid, rt << 1);
        else
            update(idx, val, mid + 1, r, rt << 1 | 1);
        pushup(rt);
    }

    int query(int L, int R, int l, int r, int rt)
    {
        if (L <= l && r <= R)
            return tree[rt];
        int mid = (l + r) >> 1;
        int res = -INF;
        if (L <= mid)
            res = max(res, query(L, R, l, mid, rt << 1));
        if (R > mid)
            res = max(res, query(L, R, mid + 1, r, rt << 1 | 1));
        return res;
    }
} st;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> l >> r;
    for (int i = 0; i <= n; i++)
        cin >> a[i];

    st.build(0, n, 1);
    st.update(0, 0, 0, n, 1); // f[0] = 0

    int ans = -INF;
    for (int i = 1; i <= n; i++)
    {
        int L = max(0, i - r);
        int R = i - l;
        if (L <= R)
        {
            int val = st.query(L, R, 0, n, 1);
            if (val != -INF)
            {
                st.update(i, val + a[i], 0, n, 1);
            }
        }
        if (i + r > n && st.query(i, i, 0, n, 1) != -INF)
        {
            ans = max(ans, st.query(i, i, 0, n, 1));
        }
    }
    cout << ans << endl;
    return 0;
}