#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;

int n, l;
pair<int, int> a[maxn];
bool boosted[maxn];

int main(int argc, char const *argv[])
{
    cin >> n >> l;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a + 1, a + 1 + n, greater<pair<int, int>>());

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        int idx = a[i].second;
        if (a[i].first >= i)
        {
            cnt++;
        }
        else if (l > 0 && !boosted[idx] && a[i].first + 1 >= i)
        {
            a[i].first++;
            l--;
            boosted[idx] = true;
            for (int j = i; j > 1 && a[j] > a[j - 1]; j--)
            {
                swap(a[j], a[j - 1]);
            }
            i = 0;
            cnt = 0;
        }
        else
        {
            break;
        }
    }

    cout << cnt << endl;

    return 0;
}
