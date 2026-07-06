#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int a[maxn];
int b[maxn];

void primeFactors(int n)
{
    int cnt = 1;
    if (n == 1)
    {
        b[cnt] = 1;
        return;
    }
    for (int i = 2; i * i <= n; ++i)
    {
        while (n % i == 0)
        {
            b[cnt++] = i;
            n /= i;
        }
    }
    if (n > 1)
        b[cnt++] = n;
}

int main(int argc, char **argv)
{

    return 0;
}