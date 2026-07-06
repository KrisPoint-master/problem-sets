#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 5;

long long a[maxn];
long long n, k;

void work()
{
    long long cnt = 0;
    long long pos = 1;
    for (register int i = 1; i <= n; i++)
    {
        for (register int j = pos; j <= i; j++)
        {
            long long kl = a[i] ^ a[j - 1];
            if (kl == k)
            {
                pos = i + 1;
                cnt++;
                break;
            }
        }
    }
    cout << cnt << endl;
}

int main(int argc, char **argv)
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] ^= a[i - 1];
    }

    work();

    return 0;
}