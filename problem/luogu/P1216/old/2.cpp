#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
int n, m;
int a[maxn][maxn];
int rcd[maxn];
int ans;
int cnt;

void dfs(int x, int y)
{
    rcd[x] = a[x][y];

    if (x == n)
    {
        int sum = 0;
        cnt++;
        for (int i = 1; i <= n; ++i)
        {
            sum += rcd[i];
        }
        if (ans < sum)
            ans = sum;
        return;
    }
    dfs(x + 1, y);
    dfs(x + 1, y + 1);
}

int main(int argc, char *argv[])
{
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            cin >> a[i][j];
        }
    }
    dfs(1, 1);
    std::cout << ans << "\n";

    return 0;
}