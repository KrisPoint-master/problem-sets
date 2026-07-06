/**
 * Author by Rainboy blog: https://rainboylv.com github : https://github.com/rainboylvx
 * rbook: -> https://rbook.roj.ac.cn  https://rbook2.roj.ac.cn
 * date: 2026-03-08 10:32:33
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int maxn = 2e6 + 5;
int n, a, b, d;
int k[maxn];

void init()
{
    std::cin >> n >> a >> d;
    n--;
    for (int i = 1; i <= n; ++i) // i: 1->n
    {
        std::cin >> b;
        // 转化,设 移动的次数为 k
        // b - k * 2d > 1
        // -> k *2d < b - 1
        // k < ( b-1)/2d
        // !! 注意这里的小于号 是一个坑点,需要考虑不同的情况
        // k = b-1/2d 向下取整

        if ((b - 1) % (2 * d) == 0)
            k[i] = (b - 1) / (2 * d) - 1;
        else
            k[i] = (b - 1) / (2 * d);

        if (k[i] <= 0)
            k[i] = 0;
    }

    // 考虑到起始的位置,开始可以移动一次
    k[a]++;

    // k[1] = 1;
    // k[2] = 1;
    // k[3] = 1;
    // k[4] = 0;
    // k[5] = 1;
    // k[6] = 1;
    // k[7] = 1;
    // k[a]++;

#ifndef DEBUG

    for (int i = 1; i <= n; ++i) // i: 1->n
    {
        std::cout << k[i] << " ";
    }
    std::cout << "\n";
#endif
}

int ans;
int fx[] = {-2, -1, 0, 1, 2};

void dfs(int pos, int dep)
{
    if (ans < dep)
        ans = dep;

    for (int i = 0; i <= 4; ++i) // i: 0->4
    {
        int new_p = pos + fx[i];
        if (new_p > n || new_p < 1)
            continue;
        if (k[new_p] <= 0)
            continue;

        // 特殊判断,保持不动
        // 不动, 下一轮,可能变成0
        if (fx[i] == 0 && k[pos] - 1 <= 0)
        {
            continue;
        }

        k[pos]--;
#ifdef DEBUG

// std::cout << "K: " ;
// for(int i = 1;i <= n ;++i ) // i: 1->n
// {
//     std::cout << k[i] << " ";
// }
// std::cout << "\n";
#endif
        dfs(new_p, dep + 1);
        k[pos]++;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    dfs(a, 0);
    std::cout << ans << "\n";

    return 0;
}
