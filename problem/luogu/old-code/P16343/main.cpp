#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
typedef int ll;

namespace fastIO
{
#define LOCAL
#define ll long long
    namespace ly
    {
        namespace IO
        {
#ifndef LOCAL
            constexpr auto maxn = 1 << 20;
            char in[maxn], out[maxn], *p1 = in, *p2 = in, *p3 = out;
#define getchar() (p1 == p2 && (p2 = (p1 = in) + fread(in, 1, maxn, stdin), p1 == p2) ? EOF : *p1++)
#define flush() (fwrite(out, 1, p3 - out, stdout))
#define putchar(x) (p3 == out + maxn && (flush(), p3 = out), *p3++ = (x))
            class Flush
            {
            public:
                ~Flush() { flush(); }
            } _;
#endif
            namespace usr
            {
                template <typename type>
                inline type read(type &x)
                {
                    x = 0;
                    bool flag(0);
                    char ch = getchar();
                    while (!isdigit(ch))
                        flag ^= ch == '-', ch = getchar();
                    while (isdigit(ch))
                        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
                    return flag ? x = -x : x;
                }
                template <typename type>
                inline void write(type x)
                {
                    x < 0 ? x = -x, putchar('-') : 0;
                    static short Stack[50], top(0);
                    do
                        Stack[++top] = x % 10, x /= 10;
                    while (x);
                    while (top)
                        putchar(Stack[top--] | 48);
                }
                inline char read(char &x)
                {
                    do
                        x = getchar();
                    while (isspace(x));
                    return x;
                }
                inline char write(const char &x) { return putchar(x); }
                inline void read(char *x)
                {
                    static char ch;
                    read(ch);
                    do
                        *(x++) = ch;
                    while (!isspace(ch = getchar()) && ~ch);
                }
                template <typename type>
                inline void write(type *x)
                {
                    while (*x)
                        putchar(*(x++));
                }
                inline void read(string &x)
                {
                    static char ch;
                    read(ch), x.clear();
                    do
                        x += ch;
                    while (!isspace(ch = getchar()) && ~ch);
                }
                inline void write(const string &x)
                {
                    for (int i = 0, len = x.length(); i < len; ++i)
                        putchar(x[i]);
                }
                template <typename type, typename... T>
                inline void read(type &x, T &...y) { read(x), read(y...); }
                template <typename type, typename... T>
                inline void write(const type &x, const T &...y) { write(x), putchar(' '), write(y...), sizeof...(y) ^ 1 ? 0 : putchar('\n'); }
                template <typename type>
                inline void put(const type &x, bool flag = 1) { write(x), flag ? putchar('\n') : putchar(' '); }
            }
#ifndef LOCAL
#undef getchar
#undef flush
#undef putchar
#endif
        }
        using namespace IO::usr;
    }
    using namespace ly::IO::usr;
};
using namespace fastIO;

int n, V;
int a[1005][1005];

int gcd(int a, int b)
{
    return (b != 0) ? a : gcd(b, a % b);
}

bool check(int nowi, int nowj)
{
    if (nowi < 1 || nowi > n)
        return 0;
    if (nowj < 1 || nowj > n)
        return 0;
    return 1;
}

int vis[1005][1005];
int maxans = -1;

int dfs(int nowi, int nowj, int ans)
{
    if (!check(nowi, nowj))
        return 0;
    cout << nowi << " " << nowj << " " << endl;
    if (vis[nowi][nowj])
        return vis[nowi][nowj];
    int nowv = gcd(ans, a[nowi][nowj]);
    if (nowi == n && nowj == n)
    {
        maxans = max(maxans, nowv);
        return nowv;
    }
    vis[nowi][nowj] = max(dfs(nowi + 1, nowj, nowv), dfs(nowi, nowj + 1, nowv));
    return vis[nowi][nowj];
}

signed main(int argc, const char **argv)
{
    read(n, V);
    for (int i = 1; i <= n; i++)
    {
        // for i --> n
        for (int j = 1; j <= n; j++)
        {
            // for j --> n
            read(a[i][j]);
            // cout << a[i][j] << endl;
        }
    }
    dfs(1, 1, a[1][1]);
    cout << maxans << endl;
    return 0;
}