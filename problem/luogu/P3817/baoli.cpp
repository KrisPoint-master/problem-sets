#include <bits/stdc++.h>
using namespace std;

int n, x;
int a[25], b[25];
int ans = 1e9;

void dfs(int pos, int eaten) {
    if (eaten >= ans) return;
    if (pos > n) {
        ans = min(ans, eaten);
        return;
    }
    int max_val = min(a[pos], x - b[pos - 1]);
    for (int val = 0; val <= max_val; val++) {
        b[pos] = val;
        dfs(pos + 1, eaten + (a[pos] - val));
    }
}

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> a[i];
    b[0] = 0;
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}
