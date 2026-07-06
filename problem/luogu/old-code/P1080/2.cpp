#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;

struct person
{
    __int128_t l, r;
    __int128_t sum;
    void calc() { sum = l * r; }
} p[maxn];

bool cmp(person a, person b)
{
    return a.sum < b.sum;
}

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

    short a;
    int b;
    long long c;
    __int128 d;
    char e;
    char f[20];
    string g;

    signed test()
    {
        read(a, b, c, d, e, f, g);
        write(a, b, c, d, e, f, g);
        return 0;
    }
};
using namespace fastIO;

int main(int argc, char const *argv[])
{
    long long n;
    cin >> n;
    read(p[0].l, p[0].r);
    for (int i = 1; i <= n; i++)
    {
        read(p[i].l, p[i].r);
        p[i].calc();
    }
    sort(p + 1, p + 1 + n, cmp);
    __int128_t sum = p[0].l;
    __int128_t maxsum = INT32_MIN;
    for (int i = 1; i <= n; i++)
    {
        long long t = sum / p[i].r;
        sum *= p[i].l;
        // maxsum = max(t, maxsum);
        if (t > maxsum)
            maxsum = t;
    }

    write(maxsum);

    return 0;
}
