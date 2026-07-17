#include <bits/stdc++.h>
using namespace std;

long long n;
long long a[1000005];

long long min_a = LONG_LONG_MAX;
long long max_a = LONG_LONG_MIN;

int main(long long argc, char const *argv[])
{
    cin >> n;
    for (long long i = 1; i <= n; i++)
    {
        cin >> a[i];
        min_a = min(a[i], min_a);
        max_a = max(a[i], max_a);
    }

    long long sum_money_max = LONG_LONG_MIN;
    long long ava_money_min = 0;

    for (long long m = min_a; m <= max_a; m++)
    {
        long long sum_money = 0;
        long long ava_money = 0;
        for (long long i = 1; i <= n; i++)
        {
            if (a[i] >= m)
            {
                ava_money++;
                sum_money += m;
            }
        }
        // cout << m << " ";
        // cout << sum_money << " " << ava_money << endl;
        if (sum_money_max < sum_money)
        {
            ava_money_min = m;
            sum_money_max = sum_money;
        }
    }

    cout << sum_money_max << " " << ava_money_min << endl;

    return 0;
}
