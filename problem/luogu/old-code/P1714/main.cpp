#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e7 + 10;
int n, m, ans = INT32_MIN, sum[maxn], a;
deque<int> dq;
int main()
{
    cin >> n >> m;
    dq.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        sum[i] = sum[i - 1] + a;
        while (!dq.empty() && dq.front() < i - m)
            dq.pop_front();
        ans = max(ans, sum[i] - sum[dq.front()]);
        while (!dq.empty() && sum[dq.back()] > sum[i])
            dq.pop_back();
        dq.push_back(i);
    }
    cout << ans << endl;
    return 0;
}