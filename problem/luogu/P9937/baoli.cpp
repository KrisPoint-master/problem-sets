#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;

int n, l;
int a[maxn];
bool vis[maxn];

int get_h(int a[], int n)
{
    int cnt = 0;
    sort(a + 1, a + 1 + n, greater<int>());
    for (int i = 1; i <= n; i++)
    {
        if (a[i] >= i)
        {
            cnt++;
        }
        else
        {
            break;
        }
    }

    return cnt;
}

int b[maxn];
int t[maxn];

int maxh = 0;

void dfs(int dep, int start)
{
    // evaluate current state
    memset(t, 0, sizeof(int) * (n + 1));
    memcpy(t, a, sizeof(int) * (n + 1));
    for (int i = 1; i < dep; i++)
    {
        t[b[i]]++;
    }
    int h = get_h(t, n);
    maxh = max(maxh, h);

    if (dep > l) return;

    for (int i = start; i <= n; i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            b[dep] = i;
            dfs(dep + 1, i + 1);
            b[dep] = 0;
            vis[i] = false;
        }
    }
}

int main(int argc, char const *argv[])
{
    cin >> n >> l;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    dfs(1, 1);

    cout << maxh << endl;

    return 0;
}
