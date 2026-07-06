#include<bits/stdc++.h>
using namespace std;

int n,ans;
int f[100005];

int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> f[i];
        if(f[i] > f[i-1]) ans += f[i] - f[i-1]; 
    }
    cout << ans << endl;
    return 0;
}
