#include <bits/stdc++.h>
using namespace std;

int t, n, k, q;

vector<vector<int>> ma;
vector<pair<int, int>> mq;
vector<pair<vector<int>, int>> temp;

struct State
{
    int rounds_done, last_person, last_val;
    bool operator==(const State &o) const
    {
        return rounds_done == o.rounds_done &&
               last_person == o.last_person &&
               last_val == o.last_val;
    }
};

struct StateHash
{
    size_t operator()(const State &s) const
    {
        return hash<int>()(s.rounds_done) ^
               (hash<int>()(s.last_person) << 7) ^
               (hash<int>()(s.last_val) << 13);
    }
};

unordered_map<State, bool, StateHash> memo;

void r_equ_1_spe(int c)
{
    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i].first[0] != 1)
            continue;
        int len = temp[i].first.size();
        if (len < 2 || len > k)
            continue;
        if (temp[i].first.back() == c)
        {
            cout << 1 << '\n';
            return;
        }
    }
    cout << 0 << '\n';
}

bool dfs(int rounds_done, int last_person,
         int last_val, int target_rounds, int target_last)
{
    if (rounds_done == target_rounds)
        return last_val == target_last;

    State st{rounds_done, last_person, last_val};
    auto it = memo.find(st);
    if (it != memo.end())
        return it->second;

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
        if (dfs(rounds_done + 1, temp[i].second,
                temp[i].first.back(), target_rounds, target_last))
        {
            memo[st] = true;
            return true;
        }
    }
    memo[st] = false;
    return false;
}

void solve(int idx_q)
{
    memo.clear();
    int target_rounds = mq[idx_q].first;
    int target_last = mq[idx_q].second;
    cout << dfs(0, -1, -1, target_rounds, target_last) << '\n';
}

void get_temp()
{
    for (int now = 0; now < n; now++)
    {
        int m = ma[now].size();
        for (int i = 0; i < m; i++)
            for (int j = i; j < m; j++)
            {
                vector<int> a;
                for (int k = i; k <= j; k++)
                    a.push_back(ma[now][k]);
                temp.push_back({a, now + 1});
            }
    }
}

bool init()
{
    cin >> n >> k >> q;
    for (int i = 1; i <= n; i++)
    {
        int l;
        cin >> l;
        vector<int> a(l);
        for (int j = 1; j <= l; j++)
            cin >> a[j - 1];
        ma.push_back(a);
    }

    bool all_r1 = true;
    for (int i = 1; i <= q; i++)
    {
        int r, c;
        cin >> r >> c;
        if (r != 1)
            all_r1 = false;
        mq.push_back({r, c});
    }

    if (all_r1)
    {
        get_temp();
        for (int i = 0; i < q; i++)
            r_equ_1_spe(mq[i].second);
        return true;
    }
    return false;
}

void work()
{
    get_temp();
    for (int i = 0; i < q; i++)
        solve(i);
}

void reinit()
{
    ma.clear();
    mq.clear();
    temp.clear();
    n = k = q = 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--)
    {
        reinit();
        if (!init())
            work();
    }
    return 0;
}
