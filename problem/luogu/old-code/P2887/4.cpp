#include <cstdio>
#include <algorithm>
using namespace std;
int ans;
struct cow
{
    int l;
    int r;
} ox[5000];
struct sunscreen
{
    int n;
    int s;
} bb[5000];
bool com(struct cow x, struct cow y)
{
    if (x.r < y.r)
        return true;
    return false;
}
bool comp(struct sunscreen a, struct sunscreen b)
{
    if (a.n < b.n)
        return true;
    return false;
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &ox[i].l, &ox[i].r);
    for (int i = 1; i <= m; i++)
        scanf("%d %d", &bb[i].n, &bb[i].s);
    sort(ox + 1, ox + 1 + n, com);
    sort(bb + 1, bb + m + 1, comp);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (bb[j].n >= ox[i].l && bb[j].n <= ox[i].r && bb[j].s)
            {
                bb[j].s--;
                ans++;
                break;
            }
    printf("%d", ans);
}
