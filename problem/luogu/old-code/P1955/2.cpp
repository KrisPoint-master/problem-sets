#include <bits/stdc++.h>
using namespace std;

int pa[200005];
int find(int x) { return pa[x] == x ? x : pa[x] = find(pa[x]); }

struct query
{
    int u, v, e;
};

void solve()
{
    int n;
    cin >> n;
    vector<query> q(n);
    vector<int> nums;

    for (int i = 0; i < n; i++)
    {
        cin >> q[i].u >> q[i].v >> q[i].e;
        nums.push_back(q[i].u);
        nums.push_back(q[i].v);
    }

    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    auto get_id = [&](int x)
    {
        return lower_bound(nums.begin(), nums.end(), x) - nums.begin() + 1;
    };

    int m = nums.size();
    for (int i = 1; i <= m; i++)
        pa[i] = i;

    for (int i = 0; i < n; i++)
    {
        if (q[i].e == 1)
            pa[find(get_id(q[i].u))] = find(get_id(q[i].v));
    }
    for (int i = 0; i < n; i++)
    {
        if (q[i].e == 0)
        {
            if (find(get_id(q[i].u)) == find(get_id(q[i].v)))
            {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}