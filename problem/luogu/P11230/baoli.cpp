#include <bits/stdc++.h>
using namespace std;

int t;
int n, k, q;

vector<vector<int>> ma;
vector<pair<int, int>> mq;
vector<pair<vector<int>, int>> temp; // int -> where_flag

void r_equ_1_spe(int c)
{
    int r = 1;
    for (int i = 0; i < temp.size(); i++)
    {
        int where_is = temp[i].second;
        int flag_1_if_first_is_1 =
            (temp[i].first[0] == 1);
        int flag_2_len_is_done = (2 <= temp[i].first.size()) &&
                                 (temp[i].first.size() <= k);
        int flag_3_last_val = (temp[i].first[temp[i].first.size() - 1] == c);
        if (flag_1_if_first_is_1 && flag_2_len_is_done && flag_3_last_val)
        {
            cout << 1 << endl;
            return;
        }
    }
    cout << 0 << endl;
}

bool init()
{
    cin >> n >> k >> q;
    for (int i = 1; i <= n; i++)
    {
        int l;
        cin >> l;
        vector<int> a;
        for (int j = 1; j <= l; j++)
        {
            int p;
            cin >> p;
            a.push_back(p);
        }
        ma.push_back(a);
    }

    bool if_r_equ_1 = true;

    for (int i = 1; i <= q; i++)
    {
        int r, s;
        cin >> r >> s;
        if (r != 1)
            if_r_equ_1 = false;
        mq.push_back(make_pair(r, s));
    }

    if (if_r_equ_1)
    {
        void get_temp();
        get_temp();
        for (int i = 0; i < q; i++)
        {
            r_equ_1_spe(mq[i].second);
        }
        return true;
    }
    return false;
}

void get_temp()
{
    for (int now = 0; now < n; now++)
    {
        int m = ma[now].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = i; j < m; j++)
            {
                vector<int> a;
                for (int k = i; k <= j; k++)
                {
                    a.push_back(ma[now][k]);
                }
                temp.push_back(make_pair(a, now + 1));
            }
        }
    }
#ifndef ONLINE_OJ
    for (int i = 0; i < temp.size(); i++)
    {
        for (int j = 0; j < temp[i].first.size(); j++)
        {
            cout << temp[i].first[j] << " ";
        }
        cout << endl;
    }
#endif
}

bool dfs(int rounds_done, int last_person,
         int last_val, int target_rounds, int target_last)
{
    if (rounds_done == target_rounds)
    {
        return last_val == target_last;
    }
    int need_start = (rounds_done == 0) ? 1 : last_val;
    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i].second == last_person)
            continue;
        if (temp[i].first[0] != need_start)
            continue;
        int len = temp[i].first.size();
        if (len < 2 || len > k)
            continue;
        if (dfs(rounds_done + 1,
                temp[i].second,
                temp[i].first.back(),
                target_rounds, target_last))
            return true;
    }
    return false;
}

void solve(int idx_q)
{
    int target_rounds = mq[idx_q].first;
    int target_last = mq[idx_q].second;
    int ans = dfs(0, -1, -1, target_rounds, target_last);
    cout << ans << '\n';
}

void work()
{
    get_temp();
    for (int i = 0; i < q; i++)
    {
        solve(i);
    }
}

void reinit()
{
    ma.clear();
    mq.clear();
    temp.clear();
    n = k = q = 0;
}

int main(int argc, char const *argv[])
{
    cin >> t;
    while (t--)
    {
        reinit();
        bool done = init();
        if (!done)
            work();
    }
    return 0;
}
