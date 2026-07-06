#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
int n, m;
int a[maxn][maxn];
int rcd[maxn][maxn];

int main(int argc, char *argv[])
{
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        rcd[n][i] = a[n][i];
    }
    for(int i = n-1;i>=1;i--){
        for(int j = 1;j<=i;j++){
            rcd[i][j] = max(rcd[i+1][j+1],rcd[i+1][j]) + a[i][j];
        }
    }

    cout << rcd[1][1] << endl;

    return 0;
}