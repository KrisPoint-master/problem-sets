#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// 全局变量 seed 和 B
unsigned long long seed;
int B;

// xorshift64 算法，不能修改
unsigned long long xorshift64()
{
    seed ^= seed << 13;
    seed ^= seed >> 7;
    seed ^= seed << 17;
    return seed;
}
void work();
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    cin >> seed >> B;

    vector<vector<ll>> ea(n + 1, vector<ll>(n + 1, 0)); // 横向边权：从 (i,j) 到 (i,j+1)， j=1..n-1
    vector<vector<ll>> eb(n + 1, vector<ll>(n + 1, 0)); // 纵向边权：从 (i,j) 到 (i+1,j)， i=1..n-1

    // 生成横向边权：遍历 i=1..n, j=1..n-1
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - 1; j++)
        {
            xorshift64();
            ea[i][j] = seed & ((1ULL << B) - 1);
        }
    }

    // 生成纵向边权：遍历 i=1..n-1, j=1..n
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            xorshift64();
            eb[i][j] = seed & ((1ULL << B) - 1);
        }
    }
    // 你可以从这里开始编写你的代码
    work();
    return 0;
}

void work()
{
}
