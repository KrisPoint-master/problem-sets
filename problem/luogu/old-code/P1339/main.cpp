#include <bits/stdc++.h>
using namespace std;

#define INF 0x7f7f7f7f
constexpr int maxe = 1e5 + 5;
constexpr int maxn = 1e5 + 5;

int u[maxe], v[maxe], w[maxe];

int dis[maxn];

int n, m, s, t;

void bellman_ford()
{
    int i, j;
    for (i = 1; i <= n - 1; i++)
        for (j = 1; j <= m; j++)
        {
            int ss = u[j], tt = v[j], ww = w[j];

            if (dis[ss] > dis[tt] + ww)
                dis[ss] = dis[tt] + ww;

            if (dis[tt] > dis[ss] + ww)
                dis[tt] = dis[ss] + ww;
        }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int i, j, k, l;
    cin >> n >> m >> s >> t;
    for (i = 1; i <= m; i++)
        cin >> u[i] >> v[i] >> w[i];

    for (i = 0; i <= n - 1; i++)
        dis[i] = INF;
    dis[s] = 0;

    bellman_ford();

    cout << dis[t] << endl;

    return 0;
}