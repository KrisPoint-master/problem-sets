#include <bits/stdc++.h>
using namespace std;

int b[1000005];

int main(int argc, const char **argv)
{
    int n;
    cin >> n;
    int min_l = 1000001, max_r = 0;
    for (int i = 1; i <= n; i++)
    {
        int l, r;
        cin >> l >> r;
        b[l] += 1, b[r] -= 1;
        min_l = min(min_l, l);
        max_r = max(max_r, r);
    }

    for (int i = 1; i <= max_r; i++)
    {
        b[i] += b[i - 1];
    }

    bool flag = 0;
    int l = 0;
    int r = 0;
    vector<int> a;
    for (int i = min_l; i <= max_r; i++)
    {
        if (!flag && b[i])
            flag = 1, l = i;
        if (flag && !b[i])
        {
            flag = 0;
            r = i;
            int len = r - l;
            a.push_back(len);
        }
    }

    vector<int> v2;
    flag = 0;
    for (int i = min_l; i < max_r; i++)
    {
        if (!flag && !b[i])
        {
            flag = 1;
            l = i;
        }
        if (flag && b[i])
        {
            flag = 0;
            r = i;
            int len = r - l;
            v2.push_back(len);
        }
    }

    a.push_back(0);
    v2.push_back(0);

    sort(a.begin(), a.end(), greater<int>());
    sort(v2.begin(), v2.end(), greater<int>());

    cout << a[0] << " " << v2[0] << endl;

    return 0;
}