#include <bits/stdc++.h>
using namespace std;
int a[1000005]{0};
int b[1000005]{0};

int range_sum(int l, int r)
{
    return a[r] - a[l - 1];
}

int main(int argc, char const *argv[])
{
    int s, t, n, flag = 0;
    double ans = 0.000;
    cin >> n >> s >> t;
    for (int i = 1; i <= n; i++)
    {   
        cin >> b[i];
        a[i] += a[i - 1] + b[i];
    }
    for (int i = s; i <= t; i++)
    {
        if((double)clock() / CLOCKS_PER_SEC > 0.95) break;
        for (int j = 1; j + i <= n; j++)
        {
            int end = i+j-1;
            double t = a[end]-a[j-1];
            double t2 = t / (double)(i * 1.000);
            if(t2 > ans) ans = t2;
        }
    }
    cout << fixed << setprecision(3) << ans << endl;
    return 0;
}
