#include <bits/stdc++.h>
using namespace std;

int n;
int min_a = INT32_MAX;
int a[1000005];
int f[1000005];
bool flag_all_is_neg = 1;
int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] >= 0)
            flag_all_is_neg = 0;
        min_a = min(min_a, a[i]);
    }

    if (flag_all_is_neg)
    {
        cout << *max_element(a + 1, a + 1 + n) << endl;
        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
        f[i] = max(f[i - 1] + a[i], a[i]);
        // cout << f[i] << " ";
    }
    // cout << endl;

    // cout << f[n] << endl; (WRONG)

    cout << *max_element(f + 1, f + 1 + n) << endl;

    return 0;
}
