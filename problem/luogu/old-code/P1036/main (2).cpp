#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int a[maxn];
int n, k;
int b[maxn];
int ans;

bool is_prime(int x)
{
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return 0;
    }
    return 1;
}

int n1, m1;    // n1个球,m1个相同的盒子
int rcd[maxn]; // 记录,rcd[1]=2,表示小朋友人选了球2
// int vis[maxn]; // vis[i] 表示 球i被选走了,被使用了
// 不需要vis,也不需要放回球,

// comb combination的简写
// dep 深度,pre 前一个选的数
void comb(int dep, int pre)
{
    if (dep > m1)
    {
        int sum = 0;
        // 输出选的球
        for (int i = 1; i <= m1; i++)
            sum += a[rcd[i]];
        if (is_prime(sum))
        {
            ans++;
        }
        return;
    }
    for (int i = pre + 1; i <= n1; i++)
    {
        rcd[dep] = i;
        comb(dep + 1, i); // 下一个小朋友去选
    }
}

int main(int argc, char **argv)
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    m1 = k;
    n1 = n;
    comb(1, 0);

    cout << ans << endl;

    return 0;
}