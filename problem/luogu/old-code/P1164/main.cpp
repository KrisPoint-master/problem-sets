#include <bits/stdc++.h>

using namespace std;
const int N = 110;
int a[N];
int n, m;
int a2[N][10010];
int dfs(int x, int m) {
    if (a2[x][m]) return a2[x][m];
    int ans = 0;
    if (m == 0) return 1;
    if (x == n) return 0;
    if (a[x + 1] <= m) ans += dfs(x + 1, m - a[x + 1]);
    ans += dfs(x + 1, m);  
    a2[x][m] = ans;
    return ans;
}

int main() {
    cin >> n >> m;  
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cout << dfs(0, m) << endl;
    return 0;
}

