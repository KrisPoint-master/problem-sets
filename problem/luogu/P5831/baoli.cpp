#include <bits/stdc++.h>
using namespace std;
int k, n;
int a[25];
int flag[30][30], cnt = 1;
int main()
{
    scanf("%d%d", &k, &n);
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[j]);
        for (int j = 1; j <= n; j++)
            for (int k = j; k <= n; k++)
                if (j < k)
                    flag[a[j]][a[k]]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (flag[i][j] == k)
                ans++;
    printf("%d\n", ans);
    return 0;
}
