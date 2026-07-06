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

bool cmp(cow a, cow b)
{
    // if (a.needspf.first != b.needspf.first)
    // {
    //     return a.needspf.first < b.needspf.first;
    // }
    // return a.cha < b.cha;
    return a.needspf.second < b.needspf.second;
}

bool cmp2(fspf &a, fspf &b)
{
    return a.spfs < b.spfs;
}

bool check(cow a, fspf s)
{
    if (a.needspf.first > s.spfs)
        return 0;
    if (a.needspf.second < s.spfs)
        return 0;
    if (s.temp_cover == 0)
        return 0;
    return 1;
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
    sort(spf + 1, spf + 1 + l, cmp2);

    // sort(cows + 1, cows + 1 + c, cmp);
    int ans = 0;
    for (int i = 1; i <= c; i++)
    {
        for (int j = 1; j <= l; j++)
        {
            if (check(cows[i], spf[j]))
            {
                spf[j].temp_cover--;
                ans++;
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}