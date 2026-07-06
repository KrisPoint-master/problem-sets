#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

template <typename T, int N = maxn>
struct sgt_point
{
    T tr[N * 4 + 5];
    inline int lp(int p) { return p << 1; }
    inline int rp(int p) { return (p << 1) | 1; }
    inline int mid(int l, int r) { return (l + r) >> 1; }

    inline void pushup(int p)
    {
        tr[p] = min(tr[lp(p)], tr[rp(p)]);
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
    T query(int L, int R, int l, int r, int p)
    {
        if (L <= l && r <= R)
        {
            return tr[p];
        }
        int m = mid(l, r);
        T ret = INT32_MAX;
        T ret2 = INT32_MAX;
        if (L <= m)
            ret = query(L, R, l, m, lp(p));
        if (R >= m + 1)
            ret2 = query(L, R, m + 1, r, rp(p));
        return min(ret, ret2);
    }
};
sgt_point<int> sgt;
int m, n;
int main(int argc, char const *argv[])
{
    cin >> m >> n;
    sgt.build(1, m, 1);
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        cout << sgt.query(a, b, 1, m, 1) << " " << endl;

        cout << (rand() % 1005 + 10086) % 10086;
    }

    return 0;
}
