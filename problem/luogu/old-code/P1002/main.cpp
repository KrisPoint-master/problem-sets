#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long x, y;
long long f[25][25];

bool is_ma(long long tx, long long ty)
{
    if (tx == x && ty == y)
        return 1;
    if (x + 1 == tx && y + 2 == ty)
        return 1;
    if (x + 1 == tx && y - 2 == ty)
        return 1;
    if (x + 2 == tx && y + 1 == ty)
        return 1;
    if (x + 2 == tx && y - 1 == ty)
        return 1;
    if (x - 1 == tx && y + 2 == ty)
        return 1;
    if (x - 1 == tx && y - 2 == ty)
        return 1;
    if (x - 2 == tx && y + 1 == ty)
        return 1;
    if (x - 2 == tx && y - 1 == ty)
        return 1;
    return 0;
}

// f(x,y) = f(x-1,y) + f(x,y-1)
//  f(0,0) = 1
//  f(ma) = 0
//  f(x,y) = 0 x<0 || y < 0
long long dfs(long long tx, long long ty)
{
    if (tx == 0 && ty == 0)
        return 1;
    if (tx < 0 || ty < 0)
        return 0;
    if (is_ma(tx, ty))
        return 0;
    if (f[tx][ty] != -1)
        return f[tx][ty];
    f[tx][ty] = dfs(tx - 1, ty) + dfs(tx, ty - 1);
    return f[tx][ty];
}
int main(long long argc, char *argv[])
{
    cin >> n >> m;
    cin >> x >> y;
    for (long long i = 0; i < 25; i++)
        for (long long j = 0; j < 25; j++)
            f[i][j] = -1;
    long long ans = dfs(n, m);
    cout << ans << endl;

    return 0;
}
