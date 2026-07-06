#include <bits/stdc++.h>
using namespace std;

int n,t,s[1005],b[1005];
int f[10005][10005];

int main(int argc, char const* argv[])
{
    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        f[i][0] = f[i-1][0] - s[i];
    }
    for (int i=1;i<=n;i++){
		for (int j=1;j<=i;j++){
			f[i][j]=f[i-1][j-1]+s[i];
			if (j%t==0) f[i][j]+=b[i];
			f[i][j]=max(f[i][j],f[i-1][j]-s[i]);
		}
	}
    int ans = 0;
	for (int i=0;i<=n;i++) ans=max(ans,f[n][i]);
    cout << ans;
    return 0;
}
