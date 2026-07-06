#include <bits/stdc++.h>
using namespace std;
int r;
int b[1010][1010];
int a[1010][1010];
int dfs(int i, int j)
{
    if (i == r - 1)
        return a[i][j];
    if (b[i][j] > 0)
        return b[i][j];
    return b[i][j] = max(dfs(i + 1, j), dfs(i + 1, j + 1)) + a[i][j];
}
int main()
{
    cin >> r;
    for (int i = 0; i < r; i++)
        for (int j = 0; j <= i; j++)
            cin >> a[i][j];
    dfs(0, 0);
    cout << b[0][0] << endl;
    return 0;
}
