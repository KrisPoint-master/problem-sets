#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    int x, y;
} pos;

pos A, B, horse;
int mp[30][30];

int dx[9]{0, 1, 2, 2, 1, -1, -2, -2, -1};
int dy[9]{0, 2, 1, -1, -2, -2, -1, 1, 2};

pos make_pos(int x, int y)
{
    return {x, y};
}

int is_wrong_road(pos now)
{
    return mp[now.x][now.y];
}

int check(pos now)
{
    if (now.x < 0 || now.x > B.x)
        return 0;
    if (now.y < 0 || now.y > B.y)
        return 0;
    return 1;
}

void init()
{
    A.x = A.y = 0;
    cin >> B.x >> B.y;
    cin >> horse.x >> horse.y;
    for (int i = 0; i <= 8; i++)
    {
        int nx = horse.x + dx[i];
        int ny = horse.y + dy[i];
        mp[nx][ny] = 1;
    }
}

int cmp_pos(pos A, pos B)
{
    return (A.x == B.x && A.y == B.y);
}

int dfs(pos now)
{
    if (cmp_pos(now, B))
    {
        return 1;
    }

    if (!check(now))
    {
        return 0;
    }

    pos down = make_pos(now.x, now.y + 1);
    pos right = make_pos(now.x + 1, now.y);

    int cnt = 0;
    if (!is_wrong_road(down))
    {
        cnt += dfs(down);
    }
    if (!is_wrong_road(right))
    {
        cnt += dfs(right);
    }

    return cnt;
}

int main(int argc, char const *argv[])
{
    init();
    cout << dfs(A) << endl;
    return 0;
}
