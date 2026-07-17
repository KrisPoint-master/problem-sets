#include <bits/stdc++.h>
using namespace std;

long long n;
long long a[1000005];

int main(long long argc, char const *argv[])
{
    cin >> n;
    for (long long i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    long long max_money = LONG_LONG_MIN;
    long long max_ava = LONG_LONG_MIN;
    for (int i = 1; i <= n; i++)
    {
        long long study_money = a[i];
        // r - l + 1
        long long tot_cows = n - i + 1;
        long long money = tot_cows * study_money;
        if (money > max_money)
        {
            max_money = money;
            max_ava = study_money;
        }
    }

    cout << max_money << " " << max_ava << endl;

    return 0;
}
