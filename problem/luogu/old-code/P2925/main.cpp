#include <bits/stdc++.h>
using namespace std;
int n, c;
int w[10005];
int v[10005];

int f[100005] = {0};

void Knapsack01()
{
    int i, j;
    for (i = 1; i <= n; i++)
        for (j = c; j >= w[i]; j--)
            if (f[j] < f[j - w[i]] + v[i])
                f[j] = f[j - w[i]] + v[i];
}
int main()
{
    cin >> c >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        w[i] = v[i];
    }

    Knapsack01();
    cout << f[c];
    return 0;
}
