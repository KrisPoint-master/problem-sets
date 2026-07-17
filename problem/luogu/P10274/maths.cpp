
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int INF = 1000000000;

int n, q;
string token_word[MAXN];
int group_id[MAXN];
int first_false[MAXN];
int last_false[MAXN];
int group_cnt;
int first_true_group, last_true_group;

void read_input()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> token_word[i];
    }
}

void build_groups()
{
    group_cnt = 1;
    for (int i = 1; i <= n; i++)
    {
        if (token_word[i] == "or")
        {
            group_cnt++;
        }
        else if (i % 2 == 1)
        {
            group_id[i] = group_cnt;
        }
    }

    for (int i = 1; i <= group_cnt; i++)
    {
        first_false[i] = INF;
        last_false[i] = -1;
    }

    for (int i = 1; i <= n; i += 2)
    {
        int g = group_id[i];
        if (token_word[i] == "false")
        {
            if (first_false[g] == INF)
            {
                first_false[g] = i;
            }
            last_false[g] = i;
        }
    }

    first_true_group = INF;
    last_true_group = -1;
    for (int g = 1; g <= group_cnt; g++)
    {
        if (first_false[g] == INF)
        {
            if (first_true_group == INF)
            {
                first_true_group = g;
            }
            last_true_group = g;
        }
    }
}

bool can_make(int l, int r, string want)
{
    int gl = group_id[l];
    int gr = group_id[r];

    if (first_true_group < gl || last_true_group > gr)
    {
        return want == "true";
    }

    if (want == "false")
    {
        return true;
    }

    if (first_false[gl] < l || last_false[gr] > r)
    {
        return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    read_input();
    build_groups();

    for (int i = 1; i <= q; i++)
    {
        int l, r;
        string want;
        cin >> l >> r >> want;
        cout << (can_make(l, r, want) ? 'Y' : 'N');
    }
    cout << '\n';

    return 0;
}