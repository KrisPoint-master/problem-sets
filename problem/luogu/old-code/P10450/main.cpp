#include <bits/stdc++.h>
using namespace std;

double eps = 1e-5;
double a[100005];
double s[100005];
int main(int argc, const char **argv)
{
    int n, L;
    cin >> n >> L;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    double l = 1e-6, r = 1e6;
    while (r - l > eps)
    {
        double mid = (l + r) / 2;
        for (int i = 1; i <= n; i++)
        {
            s[i] = s[i - 1] + a[i] - mid;
        }
        double ans = -1e10;
        double minv = 1e10;
        for (int i = L; i <= n; i++)
        {
            minv = min(minv, s[i - L]);
            ans = max(ans, s[i] - minv);
        }
        if (ans >= 0)
            l = mid;
        else
            r = mid;
    }

    cout << int(r * 1000) << endl;

    return 0;
}