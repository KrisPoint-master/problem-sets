#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n, L;
int a[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> L;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1, greater<int>());

    int h = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] >= i)
        {
            h = i;
        }
    }

    int target = h + 1;
    if (target <= n)
    {
        int ok = 0;
        int target_add = 0;

        for (int i = 1; i <= n; i++)
        {
            if (a[i] >= target)
            {
                ok++;
            }
            else if (a[i] + 1 >= target)
            {
                target_add++;
            }
        }

        int need = target - ok;
        if (need <= L && need <= target_add)
        {
            h = target;
        }
    }

    cout << h << endl;

    return 0;
}