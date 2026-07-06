#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;

int n;
int h[maxn];
int b[maxn];

bool task_A(vector<int> &g)
{
    int m = g.size() - 1;
    if (m == 0)
        return false;
    for (int i = 1; i <= m / 2; i++)
    {
        bool A1 = g[2 * i] > g[2 * i - 1];
        bool A2 = (2 * i + 1 <= m) ? (g[2 * i] > g[2 * i + 1]) : true;
        if (!(A1 && A2))
            return 0;
    }
    return 1;
}

bool task_B(vector<int> &g)
{
    int m = g.size() - 1;
    if (m == 0)
        return false;
    for (int i = 1; i <= m / 2; i++)
    {
        bool B1 = g[2 * i] < g[2 * i - 1];
        bool B2 = (2 * i + 1 <= m) ? (g[2 * i] < g[2 * i + 1]) : true;
        if (!(B1 && B2))
            return 0;
    }
    return 1;
}

int max_ans = 0;
vector<int> choose;

void dfs(int dep) noexcept
{
    if (dep > n)
    {
        choose.clear();
        choose.push_back(0);

        for (int i = 1; i <= n; i++)
        {
            if (b[i])
                choose.push_back(h[i]);
        }

        // printf("choosesize: %d,taskA: %d,taskB: %d\n", choose.size(), task_A(choose), task_B(choose));
        // for (auto it : choose)
        // {
        //     cout << it << " ";
        // }
        // cout << endl;

        if (choose.size() - 1 <= 1)
        {
            // A and B
            max_ans = max(max_ans, static_cast<int>(choose.size() - 1));
            return;
        }
        // IF A and B
        if (!(task_A(choose) || task_B(choose)))
            return;

        max_ans = max(max_ans, static_cast<int>(choose.size() - 1));
        return;
    }

    for (int i = 0; i <= 1; i++)
    {
        b[dep] = i;
        dfs(dep + 1);
    }
}

int main(int argc, char const *argv[])
{
    cin >> n;
    // return 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }

    dfs(1);
    cout << max_ans << endl;

    return 0;
}