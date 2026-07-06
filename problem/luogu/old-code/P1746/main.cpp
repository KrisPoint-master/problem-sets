#include <bits/stdc++.h>
using namespace std;

int n;
typedef struct
{
    int x;
    int y;
} pos;
pos a, b;
char mp[1005][1005];
int vis[1005][1005];
int fr[4] = {0, 0, 1, -1};
int rf[4] = {1, -1, 0, 0};

bool check(pos a){
    if(vis[a.x][a.y] || mp[a.x][a.y] == '1') return 0;
    if(a.x > n || a.y > n || a.x < 1 || a.y < 1) return 0;
    return 1;
}

void bfs(pos a)
{
    queue<pos> q;
    q.push(a);
    vis[a.x][a.y] = 1;
    while (!q.empty())
    {
        pos t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int tx = t.x + fr[i];
            int ty = t.y + rf[i];
            pos n;
            n = {tx,ty};
            if(check(n)){
                vis[tx][ty] = vis[t.x][t.y] + 1;
                q.push(n);
            }
        }
        
    }
}

int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> mp[i][j];
        }
    }
    cin >> a.x >> a.y >> b.x >> b.y;
    bfs(a);
    cout << vis[b.x][b.y] - 1<<endl;
    return 0;
}
