#include<bits/stdc++.h>
using namespace std;

struct pei_liao
{
    int i;
    int s,b;
}a[10005];


int n,ans = 1145141919;
int s,b,cnt;

void dfs(int dep){
    if(dep - 1 == n) return;
    b *= a[dep].b;
    s += a[dep].s;
    cnt++;
    ans = min(ans,(s-b));
    dfs(dep + 1);
    b /= a[dep].b;
    s -= a[dep].s;
    cnt--;
    dfs(dep + 1);
}

int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].s >> a[i].b;
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}
