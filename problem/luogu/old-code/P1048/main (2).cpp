#include <bits/stdc++.h>
using namespace std;

// 手动初始化数据
int n = 5, c = 7;
int w[100005];
int v[100005];

int f[1000005] = {0};

void Knapsack01()
{
    int i, j;
    for (i = 1; i <= n; i++)
        for (j = c; j >= w[i]; j--)
        {
            if (f[j] < f[j - w[i]] + v[i])
                f[j] = f[j - w[i]] + v[i];
        }
}
int main()
{
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
    }

    Knapsack01();
    printf("%d", f[n]);
    return 0;
}
