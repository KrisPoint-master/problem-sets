#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    long long x, y;
} pos;

pos A, B, horse;
long long mp[30][30];
long long f[30][30];

long long dx[9]{0, 1, 2, 2, 1, -1, -2, -2, -1};
long long dy[9]{0, 2, 1, -1, -2, -2, -1, 1, 2};

pos make_pos(long long x, long long y)
{
    return {x, y};
}

long long is_wrong_road(pos now)
{
    return mp[now.x][now.y];
}

long long check(pos now)
{
    if (now.x < 0 || now.x > B.x)
        return 0;
    if (now.y < 0 || now.y > B.y)
        return 0;
    return 1;
}

void init()
{
    memset(f, -1, sizeof(f));
    A.x = A.y = 0;
    cin >> B.x >> B.y;
    cin >> horse.x >> horse.y;
    for (long long i = 0; i <= 8; i++)
    {
        long long nx = horse.x + dx[i];
        long long ny = horse.y + dy[i];
        mp[nx][ny] = 1;
    }
}

long long cmp_pos(pos A, pos B)
{
    return (A.x == B.x && A.y == B.y);
}

long long dfs(pos now)
{
    if (!check(now))
        return 0;
    if (f[now.x][now.y] != -1)
        return f[now.x][now.y];
    if (cmp_pos(now, B))
        return f[now.x][now.y] = 1;

    pos down = make_pos(now.x, now.y + 1);
    pos right = make_pos(now.x + 1, now.y);

    long long cnt = 0;
    if (!is_wrong_road(down))
    {
        cnt += dfs(down);
    }
    if (!is_wrong_road(right))
    {
        cnt += dfs(right);
    }

    return f[now.x][now.y] = cnt;
}

int main(int argc, char const *argv[])
{
    init();
    cout << dfs(A) << endl;
    return 0;
}
