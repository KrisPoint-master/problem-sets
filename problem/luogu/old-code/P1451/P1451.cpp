#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;

int n,m;
int a[maxn][maxn];
int vis[maxn][maxn];
int dx[4] {1,-1,0,0};
int dy[4] {0,0,1,-1};

bool check(int x,int y)
{
    if(x < 1 || y < 1)
        return 0;
    if(x > n || y > m)
        return 0;
    if(vis[x][y])
        return 0;
    if(a[x][y] == 0)
        return 0;
    return 1;
}

void dfs(int x,int y)
{
    if(!check(x,y))
        return;
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(!check(nx,ny))
            continue;
        dfs(nx,ny);
    }
}

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if(vis[i][j] == 0 && a[i][j] != 0)
            {
                dfs(i,j);
                ans ++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

