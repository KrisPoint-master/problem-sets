#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int n;
double d;
int b[maxn];
int a[maxn];
double tot_d;

int spe_A_flag = INT32_MAX;
int main(int argc, char **argv)
{
    cin >> n >> d;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> a[i];
        tot_d += a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        spe_A_flag = min(b[i], spe_A_flag);
    }
    if (!spe_A_flag == b[1])
        spe_A_flag = 0;

    if (spe_A_flag)
    {
        int ans = ceil(tot_d / d);
        cout << ans << endl;
    }

    return 0;
}