#include <bits/stdc++.h>
using namespace std;

int n, x, cnt1, cnt2;
// cnt1 : even
// cnt2 : odd
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        if (x % 2 == 0)
            cnt1++;
        else
            cnt2++;
    }
    while (cnt2 > cnt1)
    {
        cnt2 -= 2;
        cnt1++;
    }
    if (cnt1 > cnt2 + 1)
        cnt1 = cnt2 + 1;
    cout << cnt1 + cnt2 << endl;
    return 0;
}
