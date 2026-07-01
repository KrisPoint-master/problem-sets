#include <bits/stdc++.h>
using namespace std;

int n, m; // n is MOD

#define START_POS 1

int next_pos(int np)
{
    /*
     * @args  : np : now pos
     * @return : next pos
     */
    return np == n ? 1 : np + 1;
}

int prev_pos(int np)
{
    /*
     * @args  : np : now pos
     * @return : prev pos
     */
    int t = (np - 1);
    return (t == 0) ? n : t;
}

int dfs(int dep, int np)
{
    /*
     * @args dep:the dfs' depth
     * @args np : now_pos
     * @return -> int : SUCCEED_COUNT
     */
    if (dep > m)
    {
        if (np == START_POS)
            return 1;
        return 0;
    }
    int t1 = dfs(dep + 1, prev_pos(np));
    int t2 = dfs(dep + 1, next_pos(np));
    return t1 + t2;
}

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    int ans = dfs(1, START_POS);
    cout << ans << endl;
    return 0;
}
