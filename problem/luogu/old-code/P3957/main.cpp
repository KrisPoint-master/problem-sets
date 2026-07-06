
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 1e18;
const int MAXN = 500005;

int n;
ll d, k;
struct point
{
    ll x, s;
} p[MAXN];

ll dp[MAXN];

bool check(ll g)
{
    ll min_dist = max(1LL, d - g);
    ll max_dist = d + g;

    for (int i = 1; i <= n; i++)
        dp[i] = -INF;
    dp[0] = 0;

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = i - 1; j >= 0; j--)
    //     {
    //         ll dist = p[i].x - p[j].x;
    //         if (dist > max_dist)
    //             continue;
    //         if (dist < min_dist)
    //             continue;
    //         if (dp[j] == -INF)
    //             continue;
    //         dp[i] = max(dp[i], dp[j] + p[i].s);
    //     }

    //     if (dp[i] >= k)
    //         return true;
    // }

    deque<int> q;
    int cur = 0;

    for (int i = 1; i <= n; i++)
    {
        while (cur < i && p[i].x - p[cur].x >= min_dist)
        {
            if (dp[cur] != -INF)
            {
                while (!q.empty() && dp[q.back()] <= dp[cur])
                    q.pop_back();
                q.push_back(cur);
            }
            cur++;
        }

        while (!q.empty() && p[i].x - p[q.front()].x > max_dist)
        {
            q.pop_front();
        }

        if (!q.empty())
        {
            dp[i] = dp[q.front()] + p[i].s;
            if (dp[i] >= k)
                return true;
        }
    }

    return false;
}

int main()
{
    cin >> n >> d >> k;

    p[0] = {0, 0};

    for (int i = 1; i <= n; i++)
    {
        cin >> p[i].x >> p[i].s;
    }
    ll left = 0, right = 1000000005;
    ll ans = -1;

    while (left <= right)
    {
        ll mid = (left + right) / 2;
        if (check(mid))
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    cout << ans << endl;

    return 0;
}