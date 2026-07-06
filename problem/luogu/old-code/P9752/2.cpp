// Author by [Rainboy](https://github.com/rainboylvx)
// date: 2024-07-17 14:51:00
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int n, m;
int a[10][10];
int b[10];

// 记录 状态i 是否合法
int bct[10];
int ans;

void chai(int state)
{
    for (int i = 5; i >= 1; i--)
    {
        b[i] = state % 10;
        state /= 10;
    }
}

// 比较b 与 a[i] 是否只有位置不同
bool only_1_diff(int x)
{
    int cnt = 0;
    for (int i = 1; i <= 5; ++i)
        cnt += a[x][i] == b[i];
    return cnt == 1;
}

bool all()
{
    for (int i = 1; i <= n; ++i) // i: 1->n
    {
        if (bct[i] == 0)
            return 0;
    }
    return 1;
}

bool check2(int x)
{
    // p1
    int cnt = 0;
    int f1 = 0; // 记录第一个位置不相同的位置
    for (int i = 1; i <= 5; i++)
    {
        if (a[x][i] != b[i])
        {
            if (cnt == 0)
            {
                f1 = i;
            }
            cnt++;
        }
    }
    // 是否是相邻的
    if (cnt == 2)
    {
        if (!(f1 < 5 && a[x][f1 + 1] != b[f1 + 1]))
            return 0;
    }
    else
        return 0;

    // 进行p2
    int k1 = b[f1];
    int k2 = b[f1 + 1];
    for (int i = 1; i <= 9; i++)
    {
        int t1 = (k1 + i) % 10;
        int t2 = (k2 + i) % 10;
        if (t1 == a[x][f1] && t2 == a[x][f1 + 1])
            return 1;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    std::cin >> n;
    for (int i = 1; i <= n; ++i) // i: 1->n
    {
        for (int j = 1; j <= 5; ++j) // j: 1->5
        {
            cin >> a[i][j];
        }
    }

    // 枚举 密码锁的可能
    for (int i = 0; i <= 99999; i++)
    {

        // i 是不是合法
        // 怎么做呢？
        // 1. 转1个圈
        // 10000 -> a[1]...
        // 11000
        memset(bct, 0, sizeof(bct));
        chai(i);
        for (int j = 1; j <= n; j++)
        {
            bct[j] = only_1_diff(j);
            if (bct[j] == 0)
            {
                bct[j] = check2(j);
            }
        }
        if (all())
            ans++;

        // 1. 转2个圈
        // A: 如何判断i是否能转2个相邻圈到达j
        // p1: 只有两个相邻元素不一样
        // p2: 这两个位置 可以 通过旋转到达
        // p1 && p2  -> A

        // check2 14 only_1_diff 5 (20*10*10^5)
    }
    std::cout << ans << "\n";

    return 0;
}