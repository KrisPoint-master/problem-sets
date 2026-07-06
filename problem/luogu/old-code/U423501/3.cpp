#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e6 + 5;
const int mod = 10007;

int n, m, k;
int a[maxn];
int target[maxn];

struct machine
{
    int l = 0;
    int o;
    long long x, y;

    machine operator+(const machine &mb)
    {
        machine m;
        m.o = 1;
        m.x = this->x;
        m.y = this->y + 1;
        m.l = this->l + mb.l;
    }

    void run_task();
} mach[maxn];
string s;
void machine::run_task()
{
    if (o == 1)
    {
        target[x] += y;
        target[x] %= mod;
    }

    if (o == 2)
        for (int i = x; i <= y; i++)
            mach[i].run_task();
}

void init()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> mach[i].o >> mach[i].x >> mach[i].y;
    }
}

template <typename T = int, int N = maxn>
struct sgt_range
{
    T tr[N * 4 + 5];
    T flag[N * 4 + 5]; // flag 里的内容与题目有关，灵活设定
    inline int lp(int p) { return p << 1; }
    inline int rp(int p) { return (p << 1) | 1; }
    inline int mid(int l, int r) { return (l + r) >> 1; }

    inline void pushup(int p)
    { // 向上合并
        tr[p] = (tr[lp(p)] + tr[rp(p)]);
    }
    inline void pushdown(int p, int m)
    { // 向下压标记
        if (flag[p])
        { // 当前点有flag
            flag[lp(p)] = flag[rp(p)] = flag[p];
            tr[lp(p)] += flag[p] * (m - (m >> 1)); // 成段替换需要这样写
            tr[rp(p)] += flag[p] * (m >> 1);
            flag[p] = 0;
        }
    }

    void build(int l, int r, int p)
    { // 建立
        if (l == r)
        {
            // scanf("%d", &tr[p]);
            tr[p] = mach[p];
            return;
        }
        int m = mid(l, r);
        build(l, m, lp(p));
        build(m + 1, r, rp(p));
        pushup(p);
    }

    // 区间更新
    void update(int L, int R, T v, int l, int r, int p)
    {
        if (L <= l && r <= R)
        {
            flag[p] = v;
            tr[p] += (r - l + 1) * v;
            return;
        }
        pushdown(p, r - l + 1); // 路过
        int m = mid(l, r);
        if (L <= m)
            update(L, R, v, l, m, lp(p));
        if (R >= m + 1)
            update(L, R, v, m + 1, r, rp(p));
        pushup(p);
    }

    // 区间查询
    T query(int L, int R, int l, int r, int p)
    {
        if (L <= l && r <= R)
        {
            return tr[p];
        }
        pushdown(p, r - l + 1);
        int m = mid(l, r);
        machine k;
        T ret = k;
        if (L <= m)
            ret += query(L, R, l, m, lp(p));
        if (R >= m + 1)
            ret += query(L, R, m + 1, r, rp(p));
        // pushup(p);
        return ret;
    }
};
sgt_range<machine> sgt;
int b[maxn];
void work()
{
    sgt.build(1, n, 1);
    for (int i = k; i >= 1; i--)
    {
        if (mach[i].o == 1)
        {
            // sgt.update(mach[i].x, mach[i].x, mach[i].y, 1, n, 1);
            machine m = sgt.query(i, i, 1, n, 1);
            b[m.x] += m.l * m.y % mod;
        }
        if (mach[i].o == 2)
        {
            sgt.update(mach[i].x, mach[i].y, mach[i], 1, n, 1);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << b[i] % mod << " ";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    work();

    return 0;
}
