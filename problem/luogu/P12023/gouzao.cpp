#include <bits/stdc++.h>
using namespace std;

int t;
int n;
vector<int> a;
map<int, int> m;

void work()
{
    cin >> n;
    a.clear();
    m.clear();
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }

    for (int i = 0; i < a.size(); i++)
    {
        m[a[i]]++;
    }

    int cnt2 = 0;
    int max_two = 0;
    int max_all = 0;
    for (auto iter : m)
    {
        if (iter.second >= 2)
        {
            cnt2++;
            max_two = max(max_two, iter.first);
        }
        max_all = max(max_all, iter.first);
    }

    int ans;
    if (cnt2 == 0)
        ans = 1;
    else if (max_two < max_all)
        ans = 2 * cnt2 + 1;
    else
        ans = 2 * cnt2 - 1;
    cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}
