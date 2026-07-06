#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2000005; // 2n 规模
long long a[MAXN], s[MAXN];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i + n] = a[i];
    }
    for (int i = 1; i < 2 * n; i++)
    {
        s[i] = s[i - 1] + a[i];
    }
    deque<int> dq;
    int ans = 0;
    for (int i = 1; i < 2 * n; i++)
    {
        while (!dq.empty() && dq.front() < i - n + 1)
            dq.pop_front();
        while (!dq.empty() && s[dq.back()] >= s[i])
            dq.pop_back();
        dq.push_back(i);
        if (i >= n)
            if (s[dq.front()] - s[i - n] >= 0)
                ans++;
    }

    cout << ans << "\n";
    return 0;
}