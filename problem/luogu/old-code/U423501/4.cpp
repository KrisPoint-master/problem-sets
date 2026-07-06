#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const int MAXM = 200005; // 机器数量
const int MAXN = 200005; // 数组长度
const int MOD = 10007;

struct Machine
{
    int o, x, y;
} mach[MAXM];

int n, m, k;
int c[MAXM];
int target[MAXN];

// 线段树：维护机器执行次数
struct SegmentTree
{
    int sum[MAXM * 4];
    int lazy[MAXM * 4];

    void pushdown(int p, int l, int r)
    {
        if (lazy[p])
        {
            int mid = (l + r) >> 1;
            lazy[p << 1] = (lazy[p << 1] + lazy[p]) % MOD;
            sum[p << 1] = (sum[p << 1] + (ll)lazy[p] * (mid - l + 1)) % MOD;

            lazy[p << 1 | 1] = (lazy[p << 1 | 1] + lazy[p]) % MOD;
            sum[p << 1 | 1] = (sum[p << 1 | 1] + (ll)lazy[p] * (r - mid)) % MOD;

            lazy[p] = 0;
        }
    }

    void update(int L, int R, int val, int l, int r, int p)
    {
        if (L <= l && r <= R)
        {
            lazy[p] = (lazy[p] + val) % MOD;
            sum[p] = (sum[p] + (ll)val * (r - l + 1)) % MOD;
            return;
        }
        pushdown(p, l, r);
        int mid = (l + r) >> 1;
        if (L <= mid)
            update(L, R, val, l, mid, p << 1);
        if (R > mid)
            update(L, R, val, mid + 1, r, p << 1 | 1);
    }

    int query(int pos, int l, int r, int p)
    {
        if (l == r)
            return sum[p];
        pushdown(p, l, r);
        int mid = (l + r) >> 1;
        if (pos <= mid)
            return query(pos, l, mid, p << 1);
        return query(pos, mid + 1, r, p << 1 | 1);
    }
} st;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++)
        cin >> c[i];
    for (int i = 1; i <= m; i++)
        cin >> mach[i].o >> mach[i].x >> mach[i].y;

    // 1. 统计顶层机器调用（初始序列 c）
    for (int i = 1; i <= k; i++)
    {
        st.update(c[i], c[i], 1, 1, m, 1);
    }

    // 2. 从后往前递推执行次数
    // 关键：i 只能调用比它小的机器，所以大的机器先算完自己的总执行次数
    for (int i = m; i >= 1; i--)
    {
        int total_f = st.query(i, 1, m, 1);
        if (total_f == 0)
            continue;

        if (mach[i].o == 2)
        {
            // 类型 2 机器：将其当前的执行次数累加给被调用的区间
            st.update(mach[i].x, mach[i].y, total_f, 1, m, 1);
        }
    }

    // 3. 计算对原数组 a 的最终贡献
    for (int i = 1; i <= m; i++)
    {
        if (mach[i].o == 1)
        {
            int f_i = st.query(i, 1, m, 1);
            int pos = mach[i].x;
            int val = mach[i].y;
            target[pos] = (target[pos] + (ll)val * f_i) % MOD;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << target[i] << (i == n ? "" : " ");
    }

    return 0;
}