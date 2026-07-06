/**
 * Author by Rainboy blog: https://rainboylv.com github : https://github.com/rainboylvx
 * date: 2025-11-07 08:27:38
 * oj: {{oj}}
 * title: {{title}}
 * description: {{description}}
 */
#include <bits/stdc++.h>
#include <cstdio>
#include <functional>
using namespace std;

typedef long long ll;

// #define NO_DEBUG // switch debug
#if defined(onlinejudge) || defined(ONLINE_JUDGE) || defined(NO_DEBUG)
#define log(...)
#define fenc
#else
#define log(args...)                             \
    {                                            \
        cout << "LINE:" << __LINE__ << " : ";    \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
    }
#define fenc cout << "================================";
void err(istream_iterator<string> it) {}

template <typename T>
void err(istream_iterator<string> it, T a)
{
    cerr << *it << " = " << a << "\n";
}

template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " = " << a << ", ";
    err(++it, args...);
}
#endif
const int maxn = 1e6 + 5;
int n, m;
long long ans;

// oisnip_begin code/utils/quick_io.cpp 内容开始
//  简化版快速IO模板
template <typename T>
inline void read(T &x)
{
    x = 0;
    T f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
    x = x * f;
}

template <typename T, typename... Args>
inline void read(T &x, Args &...args)
{
    read(x);
    read(args...); // 尾递归
}

template <typename T>
inline void write(T x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x == 0)
    {
        putchar('0');
        return;
    }

    char buf[50]; // 足够存储128位整数
    int len = 0;  // 数字长度计数器
    while (x > 0)
    { // 迭代提取每个数字位
        buf[len++] = x % 10 + '0';
        x /= 10;
    }
    // 反向输出得到正确顺序
    for (int i = len - 1; i >= 0; i--)
    {
        putchar(buf[i]);
    }
}

template <typename T, typename... Args>
inline void write(T x, Args... args)
{
    write(x);
    write(args...); // 尾递归
}

// oisnip_end code/utils/quick_io.cpp 内容结束

int a[maxn][4];

void init()
{
    for (int i = 1; i <= n; ++i) // i: 1->n
    {
        read(a[i][1]);
        read(a[i][2]);
        read(a[i][3]);
    }
}

int rcd[maxn];
int tot[4];

// 如果把 第i个元素,从 第 boxid 里面剔除
//  得到贡献是多少
int contrib(int boxid, int i)
{
    int c1, c2;
    if (boxid == 1)
        c1 = 2, c2 = 3;
    if (boxid == 2)
        c1 = 1, c2 = 3;
    if (boxid == 3)
        c1 = 1, c2 = 2;
    return -a[i][boxid] + max(a[i][c1], a[i][c2]);
}

// 最大选择的boxid
int max_choose(int a, int b, int c)
{
    if (a >= b && a >= c)
        return 1;
    if (b >= c && b >= a)
        return 2;
    return 3;
}

struct _box
{
    int a[maxn]; // 这里记录的是贡献值
    int cnt = 0;
    void clear() { cnt = 0; }

    void push(int v)
    {
        a[++cnt] = v;
    }

    int pop_last() { return a[cnt--]; }

    // 按id 表示那个盒子
    //  排序贡献
    void sort()
    {
        // std::sort(a+1,a+1+cnt,std::greater<int>());
        std::sort(a + 1, a + 1 + cnt);
    }
};

_box box[4];

signed main()
{
#ifdef FREOPEN
    freopen("in", "r", stdin);
#endif
    // std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); // 关闭io同步
    int T;
    read(T);
    while (T--)
    {
        read(n);
        init();
        box[1].clear();
        box[2].clear();
        box[3].clear();
        ans = 0;
        for (int i = 1; i <= n; ++i) // i: 1->n
        {
            int boxid = max_choose(a[i][1], a[i][2], a[i][3]);
            ans += a[i][boxid];
            box[boxid].push(contrib(boxid, i));
        }

        for (int i = 1; i <= 3; i++)
        {
            if (box[i].cnt > n / 2)
            {
                box[i].sort();

                while (box[i].cnt > n / 2)
                {
                    ans += box[i].pop_last();
                }
                break;
            }
        }
        write(ans);
        putchar('\n');
    }

    return 0;
}