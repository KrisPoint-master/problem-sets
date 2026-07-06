#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6;

long long a[maxn],b[maxn];

int main()
{
    int n, k, p, ans = 0;
    cin >> n >> k >> p;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];
    for (int i = 1; i <= n; i++)    
        for (int j = i + 1; j <= n; j++)
            if (a[i] == a[j])
                for (int k = i; k <= j; k++)
                    if (b[k] <= p){
                        ans++;
                        break;
                    }
    cout << ans;
    return 0;
}
