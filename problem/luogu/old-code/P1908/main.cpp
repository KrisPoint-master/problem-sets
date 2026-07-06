#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1000005;

// 1. 线段树部分：针对逆序对优化的点更新、区间查询
template <typename T, int N>
struct SegTree
{
    T tr[N * 4 + 5];

    // 逆序对初始桶为空，不需要 build，直接用空数组即可
    void update(int pos, T v, int l, int r, int p)
    {
        if (l == r)
        {
            tr[p] += v; // 注意是累加，处理相同数值
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid)
            update(pos, v, l, mid, p << 1);
        else
            update(pos, v, mid + 1, r, p << 1 | 1);
        tr[p] = tr[p << 1] + tr[p << 1 | 1];
    }

    T query(int L, int R, int l, int r, int p)
    {
        if (L > R)
            return 0;
        if (L <= l && r <= R)
            return tr[p];
        int mid = (l + r) >> 1;
        T ret = 0;
        if (L <= mid)
            ret += query(L, R, l, mid, p << 1);
        if (R > mid)
            ret += query(L, R, mid + 1, r, p << 1 | 1);
        return ret;
    }
};

int a[MAXN];    // 原数组
int vals[MAXN]; // 用于离散化的辅助数组
SegTree<int, MAXN> sgt;

void solve()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        vals[i] = a[i];
    }

    // 2. 离散化：不要修改原数组 a 的顺序！
    sort(vals + 1, vals + n + 1);
    int m = unique(vals + 1, vals + n + 1) - (vals + 1);

    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        // 找到 a[i] 在离散化后的排名
        int id = lower_bound(vals + 1, vals + m + 1, a[i]) - vals;

        // 核心逻辑：
        // 1. 查询当前已经进入桶中的、比 id 大的数有多少个
        ans += sgt.query(id + 1, m, 1, m, 1);
        // 2. 将当前的数放入桶中
        sgt.update(id, 1, 1, m, 1);
    }

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}