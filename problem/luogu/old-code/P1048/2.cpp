#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int T, m;
int t[maxn];
int p[maxn];
int b[maxn];

int ans = 0;
int get_tot()
{
    int s1 = 0;
    int s2 = 0;
    for (int i = 1; i <= m; ++i)
    {
        if (b[i] == 0)
            continue;
        s1 += t[i];
        s2 += p[i];
    }
    if (s1 > T)
        return -1;
    return s2;
}
void dfs(int dep)
{
    if (dep > m)
    {
        int t = get_tot();
        if (ans < t)
            ans = t;
        return;
    }
    for (int i = 0; i <= 1; ++i)
    {
        b[dep] = i;
        dfs(dep + 1);
    }
}

int main(int argc, char *argv[])
{
    cin >> T >> m;

    for (int i = 1; i <= m; ++i)
    {
        cin >> t[i] >> p[i];
    }
    dfs(1);
    cout << ans << "\n";

    return 0;
}