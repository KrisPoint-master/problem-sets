#include <bits/stdc++.h>
using namespace std;

int n;

typedef struct
{
    int id;
    int char_c; // 0 : (    1 : )
    Node *fa;
    int fa_idx;
} Node;

int bra_arr[100005];
Node tree[100005];

int s[1000005];

int check_bra_count(string str)
{
    stack<char> s;
    int cnt = 0;

    for (auto p : str)
    {
        if (p == '(')
        {
            s.push(p);
        }
        else if (p == ')')
        {
            if (!s.empty())
            {
                s.pop();
                cnt++;
            }
        }
    }

    return cnt;
}

void dfs(int start, int end, int nowid)
{
}

int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        bra_arr[i] = (c == ')'); // 0 : (    1 : )
    }

    tree[1] = {1, bra_arr[1], nullptr, NULL};

    for (int i = 2; i <= n; i++)
    {
        int fa_i;
        cin >> fa_i;
        tree[i] = {i, bra_arr[i], &tree[fa_i], fa_i};
    }

    for (int i = 2; i <= n; i++)
    {
        dfs(1, i, 1);
    }

    return 0;
}
