#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e6 + 5;

int f[maxn];
int cnt = 1;
map<int, int> ma;

int main(int argc, char const *argv[])
{
    memset(f, -1, sizeof(f));
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        long long l;
        cin >> l;
        f[++cnt] = l;
        int sum = 0;
        int p = 1;
        if (ma[f[cnt - 1]] != 0)
        {
            p = f[cnt - 1] + 1;
            sum += ma[f[cnt - 1]];
        }
        for (int i = p; i <= l; i++)
        {
            sum += pow(i, (double)((double)1 / (double)3));
        }
        ma[f[cnt]] = sum;
        cout << sum << endl;
    }

    return 0;
}
