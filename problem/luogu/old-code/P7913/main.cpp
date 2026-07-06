#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int a[3][maxn], b[3][maxn];
int n, m1, m2;
vector<vector<queue<int>>> lang;

int main(int argc, char **argv)
{
    cin >> n >> m1 >> m2;
    for (int i = 1; i <= m1; i++)
    {
        cin >> a[1][i] >> b[1][i];
    }
    for (int i = 1; i <= m2; i++)
    {
        cin >> a[2][i] >> b[2][i];
    }

    for (int i = 0; i <= n; i++)
    {
        int cty = i;
        int ouy = n - i;
        // lang[1][cty]
        // lang[2][ouy]
        if (lang[1][cty].front())
    }

    return 0;
}