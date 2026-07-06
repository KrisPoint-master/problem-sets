#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int n, m1, m2;
vector<pair<int, int>> gn;
vector<pair<int, int>> gw;

void init()
{
    cin >> n >> m1 >> m2;
    for (int i = 1; i <= m1; i++)
    {
        int p, q;
        cin >> p >> q;
        gn[i] = make_pair(p, q);
    }
    for (int i = 1; i <= m2; i++)
    {
        int p, q;
        cin >> p >> q;
        gw[i] = make_pair(p, q);
    }
}

void work()
{
    for (int i = 1; i <= n; i++)
    {
        int gncnt = i, gwcnt = n - i;
        for (int k = 1; k <= gncnt; k++)
        {
        }
    }
}

int main(int argc, char **argv)
{
    init();
    work();
    return 0;
}