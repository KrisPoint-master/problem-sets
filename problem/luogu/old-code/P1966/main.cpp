#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int n;
int a[maxn], b[maxn];
int c[maxn];
int debug = 1;
// baoli next_pre
int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    int ans = INT32_MAX;
    do
    {
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            sum += (a[i] - b[i]) * (a[i] - b[i]);
        }
        ans = min(ans, sum);
        cout << "sum: " << sum << endl;
        for (int i = 1; i <= n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
        for (int i = 1; i <= n; i++)
        {
            cout << b[i] << " ";
        }
        cout << endl
             << endl;
        if (ans == sum)
        {
            memcpy(c, a, size(a));
        }

    } while (next_permutation(a + 1, a + 1 + n));
    cout << endl
         << endl
         << "!!!!!!" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << c[i] << " ";
    }
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
    cout << ans << endl
         << endl;

    return 0;
}
