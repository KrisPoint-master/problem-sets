#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

struct Dsu
{
    int fa[maxn];
    Dsu(int n)
    {
        for (int i = 1; i <= n; i++)
            fa[i] = i;
    }

    int find(int x)
    {
        if (fa[x] == x)
            return x;
        return find(fa[x]);
    }

    bool query(int x, int y)
    {
        if (this->find(x) == this->find(y))
            return 1;
        return 0;
    }

    void _union(int x, int y)
    {
        fa[this->find(x)] = this->find(y);
    }
};

int n, m, p;

int main(int argc, char **argv)
{
    cin >> n >> m >> p;
    Dsu dsu(n);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        dsu._union(x, y);
    }

    for (int i = 1; i <= p; i++)
    {
        int x, y;
        cin >> x >> y;
        if (dsu.query(x, y))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}