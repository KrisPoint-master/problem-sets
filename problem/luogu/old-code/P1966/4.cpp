#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e8 - 3;
const int MAXN = 100005;

struct Node
{
    int val;
    int id;
};

// 用于离散化：按高度排序获取排名
bool cmp(Node x, Node y)
{
    return x.val < y.val;
}

int tree[MAXN * 4];

void update(int node, int start, int end, int pos)
{
    if (start == end)
    {
        tree[node]++;
        return;
    }
    int mid = (start + end) / 2;
    if (pos <= mid)
        update(2 * node, start, mid, pos);
    else
        update(2 * node + 1, mid + 1, end, pos);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query(int node, int start, int end, int l, int r)
{
    if (r < start || end < l)
        return 0;
    if (l <= start && end <= r)
        return tree[node];
    int mid = (start + end) / 2;
    return query(2 * node, start, mid, l, r) + query(2 * node + 1, mid + 1, end, l, r);
}

Node a[MAXN], b[MAXN];
int rka[MAXN], rkb[MAXN], c[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].val;
        a[i].id = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i].val;
        b[i].id = i;
    }

    // 1. 离散化得到排名映射
    sort(a + 1, a + 1 + n, cmp);
    sort(b + 1, b + 1 + n, cmp);

    // rka[排名] = 原本在a中的位置，rkb类似
    // 目标是让 a[i] 和 b[i] 排名相同，所以构造 C 数组
    for (int i = 1; i <= n; i++)
    {
        c[a[i].id] = b[i].id;
    }

    // 2. 线段树求 C 数组的逆序对
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        // 查询当前桶里比 c[i] 大的数（即区间 [c[i]+1, n]）
        ans = (ans + query(1, 1, n, c[i] + 1, n)) % MOD;
        update(1, 1, n, c[i]);
    }

    cout << ans << endl;

    return 0;
}