#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

struct cow
{
    int id;
    pair<int, int> needspf;
    int nowspfid = -1;
    int cha;
} cows[maxn];

struct fspf
{
    int spfs;
    int cover;
    int temp_cover;
} spf[maxn];

int c, l;

bool cmp(cow &a, cow &b)
{
    return a.cha < b.cha;
}

inline bool check_spf_for_cows(int cowsid)
{
    if (!(cows[cowsid].needspf.first <= spf[cows[cowsid].nowspfid].spfs))
        return 0;
    if (!(spf[cows[cowsid].nowspfid].spfs <= cows[cowsid].needspf.second))
        return 0;
    if (spf[cows[cowsid].nowspfid].temp_cover < 0)
        return 0;
    return 1;
}
int maxans;
void dfs(int dep)
{
    if (dep > c) // c = n;
    {
        int ans = 0;
        for (int i = 1; i <= c; i++)
        {
            // cout << i << " " << cows[i].nowspfid << endl;
            if (check_spf_for_cows(i))
            {
                ans++;
            }
        }
        maxans = max(ans, maxans);
        // cout << endl;
        return;
    }
    for (int i = 1; i <= l; i++)
    {
        cows[dep].nowspfid = i;
        spf[i].temp_cover--;
        if (spf[i].temp_cover < 0)
        {
            spf[i].temp_cover++;
            cows[dep].nowspfid = -1;
            continue;
        }
        dfs(dep + 1);
        spf[i].temp_cover++;
        cows[dep].nowspfid = -1;
    }
}
int vis[maxn];
int main(int argc, char **argv)
{
    cin >> c >> l;
    for (int i = 1; i <= c; i++)
    {
        cows[i].id = i;
        cin >> cows[i].needspf.first >> cows[i].needspf.second;
        cows[i].cha = cows[i].needspf.second - cows[i].needspf.first + 1;
    }
    for (int i = 1; i <= l; i++)
    {
        cin >> spf[i].spfs >> spf[i].cover;
        spf[i].temp_cover = spf[i].cover;
    }

    sort(cows + 1, cows + 1 + c, cmp);
    int ans = 0;
    for (int i = 1; i <= c; i++)
    {
        for (int j = 1; j <= l; j++)
        {
            if ((cows[i].needspf.first <= spf[j].spfs) &&
                (spf[j].spfs <= cows[i].needspf.second) &&
                (spf[j].temp_cover > 0))
            {
                spf[j].temp_cover--;
                vis[i] = 1;
                break;
            }
        }
    }

    for (int i = 1; i <= c; i++)
        if (vis[i])
            ans++;

    cout << ans << endl;

    // bushi 怎么有后效性

    return 0;
}