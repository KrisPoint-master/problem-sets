#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

inline void print(int n)
{
    if (n < 0)
    {
        putchar('-');
        n *= -1;
    }
    if (n > 9)
        print(n / 10);
    putchar(n % 10 + '0');
}

int main(int argc, char **argv)
{
    int n;
    cin >> n;
    __int128_t ans = -1;
    long long pos = -1;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        if (ans < t)
        {
            pos = i;
            ans = t;
        }
    }

    cout << pos << endl;
    print(ans);

    return 0;
}