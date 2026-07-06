#include <iostream>
using namespace std;
long long n, f[20][20];
long long dfs(long long x, long long y)
{
    if (f[x][y] != 0)
        return f[x][y];
    if (x == 0)
        return 1;
    if (y > 0)
        f[x][y] += dfs(x, y - 1);
    f[x][y] += dfs(x - 1, y + 1);
    return f[x][y];
}
int main()
{
    // freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    cout << "long long a[50]{";
    for (int n = 1; n <= 50; n++)
    {
        cout << dfs(n, 0) << ",";
    }
    cout << "};";
    // cin >> n;
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
int n;
const int maxn=100;

template<typename T = int,int siz = maxn>
struct mystack{
  T sta[siz+5];
  int head = 0;

  void clear() { head = 0;}

  void push(T a) { sta[head++] = a;}

  void pop(){head--;}

  T top() { return sta[head-1];}

  bool empty() { return head == 0;}

  int size() { return head;}
};

mystack<int> sta1,sta2;

int dfs() {
  if(sta1.empty()) {
    return 1;
  }
  int a = sta1.top();
  sta1.pop();
  sta2.push(a);
  int cnt = 0;
  cnt += dfs();
  sta1.push(a);
  sta2.pop();

  if( !sta2.empty()){
    a = sta2.top();
    sta2.pop();
    cnt+=dfs();
    sta2.push(a);
  }
  return cnt;
}

int main() {
  cin >> n;
  for(int i =n;i>=1;i--) {
    sta1.push(i);
  }
  int ans = dfs();
  cout << ans;
  return 0;
}

*/