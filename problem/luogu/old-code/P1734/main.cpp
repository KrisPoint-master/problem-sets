#include<bits/stdc++.h>
using namespace std;
int n,m,ans,cnt;
int a[10005],b[1005],f[1005][1005];
// S就是背包容量V，i就是重量，i的因子和就是价值
int find(int n){
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        if(n % i == 0) sum += i;
    }
    return sum;
}

int main(int argc,char **argv)
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        a[i] = find(i);
        b[i] = i;
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = b[i];j <= n;j++)
        {
            f[i][j] = f[i-1][j];
            f[i][j] = max(f[i][j],f[i-1][j-b[i]]+a[i]);
        }
    }
    cout << f[n][n] << endl;
    return 0;
}