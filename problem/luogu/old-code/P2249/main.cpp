#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;

int a[maxn];
int n, m;

int main(int argc, char **argv)
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < m; i++)
    {
        int q;
        cin >> q;
        auto l = lower_bound(a + 1, a + 1 + n, q);
        if (l != a + 1)
        {
            auto last_less = l - 1;
            // std::cout << "Last element less than " << q << " is " << *last_less << " at index " << (last_less - a + 1) << std::endl;
            cout << (last_less - a + 1) << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }

    return 0;
}