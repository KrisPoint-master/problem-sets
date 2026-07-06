#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 2e6 + 5;

int n, m;
int a[maxn], b[maxn];

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int l = 1, r = 1, k = 1, ans = maxn, minl = 1, minr = 1;
    b[a[1]] = 1; // init data to find the min
    // b array for in the query how many drawer to draw
    while (l <= r && r <= n)
    {
        if (k == m)
        {
            ans = r - l + 1;
            minl = l, minr = r;
            b[a[l]]--;
            if (b[a[1]] == 0)
                k--;
            l++;
            // array find.
        }
        else
        {
            r++;
            b[a[r]]++;
            if (b[a[r]] == 1)
                k++;
            // array no find.
        }
    }
    cout << minl << " " << minr << endl;

    return 0;
}
