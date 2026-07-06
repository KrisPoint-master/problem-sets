#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6+5;
int rcd[maxn];
int n,m;
int maxans = INT32_MIN;
struct candy
{
    int x,y;
}c[maxn];

int calcmoney(int i,int dep)
{
    int l = i / 2; //  l = 3 / 2 = 1
    int k = i - l; //  k = 2
    int money = k * c[dep].x + l * c[dep].y;
    return money;
}

int dfs(int money,int dep)
{   
    // for (int i = 0; i <= (n-dep) * 2; i++)
    //     {
    //         cout << ' ';
    //     }
    // cout  << "DEP : " << dep  << "   money : " << money << endl;
    int maxcandycount = INT32_MIN;
    if(money <= 0 || dep <= 0)
    {
        return 0;
    }
    if(dep == 1)
    {
        // int cnt = money / (c[dep].x + c[dep].y);
        // cnt *= 2;
        // if(money - cnt * (c[dep].x + c[dep].y) >= c[dep].x)
        // {
        //     cnt++;
        // }
        int cnt = money / (c[dep].x + c[dep].y);
        cnt *= 2;
        if(money - cnt * (c[dep].x + c[dep].y) >= c[dep].x)
        {
            cnt++;
        }
        for (int i = 1; i <= n; i++)
        {
            cout << rcd[i] << " ";
            
        }
        
        return cnt;
    }
    // (money - ( (money / ((c[dep].x + c[dep].y))) * 2) >= c[dep].x)
    // for (int i = 0; i < ((money / ((c[dep].x + c[dep].y)+1)) * 2 + c[dep].x); i++)
    // for (int i = 0; i <= ((money - ( (money / ((c[dep].x + c[dep].y))) * 2) >= c[dep].x) 
    // ? ((money / ((c[dep].x + c[dep].y))) * 2 + c[dep].x) 
    // : ((money / ((c[dep].x + c[dep].y))) * 2)); i++)
    for (int i = 0; i <= m; i++)
    {
        // for (int i = 0; i <= (n-dep) * 2; i++)
        // {
            // cout << ' ';
        // }
        // cout  << "2   DEP : " << dep  << "   CHOOSE : " << i << endl;
        if(calcmoney(i,dep) > money) continue;
        rcd[dep] = i;
        int candy = dfs(money - calcmoney(i,dep),dep-1);
        candy += i;
        maxcandycount = max(maxcandycount,candy);
    }
    for (int i = 0; i <= (n-dep) * 2; i++)
        {
            cout << ' ';
        }
    // cout << "MAX CANDY COUNT : " << maxcandycount << endl;
    return maxcandycount;
}

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i].x >> c[i].y;
    }
    
    int cnt = dfs(m,n);
    
    cout << cnt << endl;
    return 0;
}
