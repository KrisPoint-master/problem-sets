#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;

int n, m;
int x[maxn];

int b[maxn];

int max_ans = INT32_MIN;

void dfs(int dep, int cnt)
{
    if (cnt > m)
    {
        return;
    }
    if (dep > n && cnt != m)
    {
        return;
    }
    if (dep > n && cnt == m)
    {
        int prev = -1;
        int minv = INT32_MAX;
        for (int i = 1; i <= n; i++)
        {
            if (b[i])
            {
                if (prev == -1)
                {
                    prev = x[i];
                    continue;
                }
                int sub = x[i] - prev;
                minv = min(minv, sub);
                prev = x[i];
            }
        }

        max_ans = max(minv, max_ans);
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
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }

    sort(x + 1, x + 1 + n);

    dfs(1, 0);

    cout << max_ans << endl;

    return 0;
}
