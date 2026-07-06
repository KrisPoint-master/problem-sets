#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
int n, mm;
map<int, int> m;
struct node
{
    int pos, f1, f2;
} a[maxn];
inline bool cmp(node x, node y)
{
    if (x.f1 != y.f1)
        return x.f1 > y.f1;
    return x.f2 > y.f2;
}
int main()
{
    cin >> n;
    int x;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        m[x]++;
    }
    cin >> mm;
    for (int i = 1; i <= mm; ++i)
    {
        cin >> x;
        a[i].pos = i;
        a[i].f1 = m[x];
    }
    for (int i = 1; i <= mm; ++i)
    {
        cin >> x;
        a[i].f2 = m[x];
    }
    sort(a + 1, a + mm + 1, cmp);
    cout << a[1].pos << endl;
    return 0;
}
