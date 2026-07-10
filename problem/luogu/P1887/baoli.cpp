#include <bits/stdc++.h>
using namespace std;

int n, m;
int b[100005];

long long maxans = INT32_MIN;

int a[100005];

void dfs(int remaining, int dep)
{
    if (dep > m)
    {
        if (remaining == 0)
        {
            long long sum = 1;
            for (int i = 1; i <= m; i++)
                sum *= b[i];
            if (sum > maxans)
            {
                memcpy(a, b, sizeof(b));
                maxans = sum;
            }
        }
        return;
    }
    for (int val = 1; val <= remaining - (m - dep); val++)
    {
        b[dep] = val;
        dfs(remaining - val, dep + 1);
    }
}

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    dfs(n, 1);
    for (int i = 1; i <= m; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    // cout << maxans << endl;
    return 0;
}
