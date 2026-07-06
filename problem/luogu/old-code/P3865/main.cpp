#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[1000005];
int f[1000005][55];

void initst()
{
    for (int i = 1; i <= n; i++)
    {
        f[i][0] = a[i];
    }

    for (int k = 1; k <= 50; k++)
    {
        for (int i = 1; i + (1 << k) <= n+1; i++)
        {
            f[i][k] = max(f[i][k-1],f[i + 1 << (k - 1)][k-1]);
        }
    }
}

int highbit(int n)
{
    return sizeof(int) * 8 - 1 - __builtin_clz(n);
}

bool can_reach(int pos,int end) {
    if( pos > n) return  0;
    return pos <= end;
}

int questions_ans(int l ,int r)
{
    int start = l - 1;
    int maxk = highbit(n);

    int ans = a[l];
    for (int k = maxk; k >= 0; k--)
    {
        int new_pos = start += (1 << k);
        if(can_reach(new_pos,r))
        {
            ans = max(ans,f[start+1][k]);
            start += (1 << k);
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        // a[i] = read();
        cin >> a[i];
    }

    initst();

    for (int p = 1; p <= m; p++)
    {
        int l,r;
        // l = read(),r = read();
        cin >> l >> r;
        cout << questions_ans(l,r) << endl;
    }
    
    
    return 0;
}
