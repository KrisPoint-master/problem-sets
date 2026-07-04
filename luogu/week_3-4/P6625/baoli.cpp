#include <bits/stdc++.h>
using namespace std;

int n;
int a[20];
int b[20];
long long ans = 0;

void dfs(vector<long long> cur, long long score) {
  ans = max(ans, score);
  int m = cur.size();
  for (int k = 2; k <= m; k++) {
    long long sum = 0;
    for (int i = 0; i < k; i++)
      sum += cur[i];
    vector<long long> nxt;
    nxt.push_back(sum);
    for (int i = k; i < m; i++)
      nxt.push_back(cur[i]);
    dfs(nxt, score + sum);
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = b[i - 1] + a[i];
  }
  vector<long long> cur;
  for (int i = 1; i <= n; i++)
    cur.push_back(a[i]);
  dfs(cur, 0);
  cout << ans << endl;

  //    for (int i = 1; i <= n; i++)
  //    {
  //        cout << b[i] << endl;
  //    }

  return 0;
}
