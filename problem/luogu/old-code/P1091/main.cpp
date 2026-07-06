#include <bits/stdc++.h>
using namespace std;
#define maxn 10005
int n, cnt, ans;
int a[maxn], f[maxn], f2[maxn];

void print(int a[]){
    for(int i = 1;i<=n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        f[i] = 1;
        for (int j = 1; j < i; j++)
        {
            if (a[i] > a[j])
            {
                f[i] = max(f[i], f[j] + 1);
            }
        }
    }

    for (int i = n; i >= 1; i--)
    {
        f2[i] = 1;
        for (int j = n; j > i; j--)
        {
            if (a[i] > a[j])
            {
                f2[i] = max(f2[i], f2[j] + 1);
            }
        }
    }

    // print(f);
    // print(f2);
 

    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, f[i] + f2[i] - 1);
    }

    cout << n - ans << endl;

    return 0;
}
