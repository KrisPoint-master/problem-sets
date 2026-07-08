#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 5;

typedef pair<int, int> P; // pos

int n, m, a, b;
int ma[maxn][maxn], mb[maxn][maxn];
vector<P> pma, pmb;

int main(int argc, char const *argv[])
{
    int q;
    void work();
    cin >> q;
    while (q--)
    {
        work();
    }
    return 0;
}

void init()
{
    cin >> n >> m >> a >> b;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char t;
            cin >> t;
            ma[i][j] = (t == 'x');
            pma.push_back(make_pair(i, j));
        }
    }
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            char t;
            cin >> t;
            mb[i][j] = (t == 'x');
            pmb.push_back(make_pair(i, j));
        }
    }
}

void reinit()
{
    pma.clear();
    pmb.clear();
    memset(ma, 0, sizeof ma);
    memset(mb, 0, sizeof mb);
}

inline void print(bool flag)
{
    printf("%s", (flag) ? "TAK" : "NIE");
}

void work()
{
    int check(vector<P> pma, vector<P> pmb,
              P it_seal, P it_paper);
    reinit();
    init();

    // pma : map in paper
    // pmb : map in seal

    for (auto it_seal : pmb)
    {
        for (auto it_paper : pma)
        {
            check(pma, pmb, it_seal, it_paper);
        }
    }
}

int mapp[maxn][maxn];

void reinit_check()
{
    memset(mapp, 0, sizeof mapp);
}

int check(vector<P> pma, vector<P> pmb,
          P it_seal, P it_paper)
{
}