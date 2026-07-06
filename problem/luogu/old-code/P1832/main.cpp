#include <bits/stdc++.h>
using namespace std;

long long p[10005],f[1005];

int isprime(long long a){
    for (int i = 2; i*i <= a; i++)
    {
        if(a % i == 0) return 0;
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    int n,ans = 0;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        if(isprime(i)) p[++ans] = i;
    }
    f[0] = 1;
    for (int i = 1; i <= ans; i++)
    {
        for (int j = p[i]; j <= n; j++)
        {
            f[j] += f[j-p[i]];   
        }
    }
    cout << f[n];
    
    return 0;
}
