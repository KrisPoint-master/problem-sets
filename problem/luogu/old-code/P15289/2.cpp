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
long long n, a, b, d;
long long k[maxn]{0};

void init()
{
    std::cin >> n >> a >> d;
    n--;
    for (long long i = 1; i <= n; ++i) // i: 1->n
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
    // k[a]++;

#ifdef DEBUG

    for (long long i = 1; i <= n; ++i) // i: 1->n
    {
        std::cout << k[i] << " ";
    }
    std::cout << "\n";
#endif
}

long long ans;
long long fx[] = {-2, -1, 0, 1, 2};

void work()
{
    long long l = 0, r = 0;
    for (long long i = a; i <= n; ++i)
    {
        if (!k[i] && (k[i - 1] < 2 || k[i + 1] < 2))
            break;
        l += k[i];
    }
    for (long long i = a - 1; i >= 1; --i)
    {
        if (!k[i] && !k[i - 1])
            break;
        l += k[i];
    }

    for (long long i = a; i >= 1; i--)
    {
        if (!k[i] & (k[i - 1] < 2 || k[i + 1] < 2))
            break;
        r += k[i];
    }
    for (long long i = a + 1; i <= n; i++)
    {
        if (!k[i] && !k[i + 1])
            break;
        r += k[i];
    }

    // cout << l << " " << r << endl;
    cout << max(l, r) << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    work();
    return 0;
}
