#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int a[maxn];
map<int, int> mazl;
map<int, int> buck;

int b[maxn];
int dec2bin(int n)
{
    int len = 0;
    while (n)
    {
        b[++len] = n % 2;
        n /= 2;
    }
    return len;
}

struct luogu
{
    int n, m, c, k;
    int sum = 0;
    inline void test()
    {
        for (int i = 1; i <= 7; i++)
        {
            int l = dec2bin(i);
            for (int j = 1; j <= l; j++)
            {
                cout << b[j] << " ";
            }
            cout << endl;
        }
    }

    void init()
    {
        cin >> n >> m >> c >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            sum |= a[i];
        }
        for (int i = 1; i <= m; i++)
        {
            int p, q;
            cin >> p >> q;
            mazl[p] = q;
        }
    }
    void work()
    {
        int p = dec2bin(sum);
        for (int i = 0; i < p; i++)
        {
            if (!mazl[i] && b[i])
                buck[mazl[i]] = 1;
        }

        // int sumbin[70];
        int cnt_b = 0;
        // memcpy(sumbin, b, sizeof(b));
        for (int i = 0; i <= pow(2, n) - 1; i++)
        {
            int flag = 0;
            int len = dec2bin(i);
            for (int j = 0; j < len; j++)
            {
                if (!buck[mazl[j]] && b[j])
                {
                    flag = 1;
                    continue;
                }
            }
            if (!flag)
                cnt_b++;
        }
        cnt_b -= n;
        cout << cnt_b << endl;
    }
    void print()
    {
    }
};

int main(int argc, char const *argv[])
{
    luogu p;
    // p.test();
    p.init(), p.work(), p.print();
    return 0;
}
