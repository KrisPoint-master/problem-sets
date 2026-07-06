#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7;
int n,m;
long long w[maxn];
long long v[maxn];
unsigned long long f[maxn];

int main (int argc, char *argv[]) {
    std::cin >> m >> n;

    for(int i = 1;i <= n ;++i )
        cin >> w[i] >> v[i];

    for(int i = 1;i <= n ;++i )
        for(int j = w[i];j <= m ;++j )
            f[j] = max(f[j],f[j-w[i]] +v[i]);
    cout << f[m] <<endl;
    return 0;
}

