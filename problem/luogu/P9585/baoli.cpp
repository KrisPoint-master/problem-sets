#include <bits/stdc++.h>
using namespace std;

int n, m;
int b[105];
int minans = INT32_MAX;

void dfs(int dep, int cnt)
{
    if (cnt > n)
    {
        return;
    }
    if (dep > m)
    {
        if (cnt != n)
            return;
        int ans = 0;
        for (int i = 1; i <= m; i++)
        {
            if (b[i] == 0)
                continue;
            int prev = ((i - 1) == 0) ? m : i - 1;
            int next = i % m + 1;
            if (b[prev])
                ans++;
            if (b[next])
                ans++;
        }
        minans = min(minans, ans);

        return;
    }
    for (int i = 0; i <= 1; i++)
    {
        b[dep] = i;
        dfs(dep + 1, cnt + i);
    }
}

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    dfs(1, 0);
    cout << minans << endl;
    return 0;
}
