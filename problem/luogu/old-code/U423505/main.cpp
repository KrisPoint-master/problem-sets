#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int a[maxn]; // num
int c[maxn]; // color

int main(int argc, char const *argv[])
{
    int m, n;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        c[i] = i;
    }

    do
    {
        do
        {
            stack<int> s;
            
        } while (next_permutation(c + 1, c + 1 + n));
    } while (next_permutation(a + 1, a + 1 + n));

    return 0;
}
