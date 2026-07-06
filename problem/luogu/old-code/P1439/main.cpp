#include<bits/stdc++.h>
using namespace std;

int s1[10000];
int s2[10000];

int f[1000][1000];

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> s1[i];
    }
    for(int i = 1;i <= n;i++){
        cin >> s2[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = max(f[i-1][j],f[i][j-1]);
            if(s1[i] == s2[j]) f[i][j] = f[i-1][j-1]+1;
        }
    }
     
    cout << f[n][n];
    return 0;
}