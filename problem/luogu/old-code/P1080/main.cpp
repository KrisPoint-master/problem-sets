#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

pair<int, int> p[maxn];
int l[maxn];
int n;
int main(int argc, char **argv)
{
    cin >> n;
    cin >> p[0].first >> p[0].second;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i].first >> p[i].second;
        l[i] = i;
    }
    int minans = INT32_MAX;
    do
    {
        int sum = p[0].first;
        int ans = INT32_MIN;
        for (int i = 1; i <= n; i++)
        {
            // cout << p[l[i]].first << " " << p[l[i]].second << endl;
            int t = floor(sum / p[l[i]].second);
            sum *= p[l[i]].first;
            ans = max(ans, t);
        }
        minans = min(minans, ans);
        // cout << endl;
    } while (next_permutation(l + 1, l + 1 + n));
    cout << minans << endl;
    return 0;
}