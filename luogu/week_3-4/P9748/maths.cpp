#include <bits/stdc++.h>
using namespace std;

int n, res1, res2;

int main()
{

    cin >> n;

    for (int i = 1;; ++i)
    {
        if (n == 0)
            break;
        if (!res2 && n % 3 == 1)
            res2 = i;
        n -= ceil(n / 3.0);
        ++res1;
    }

    cout << res1 << ' ' << res2 << '\n';

    return 0;
}
