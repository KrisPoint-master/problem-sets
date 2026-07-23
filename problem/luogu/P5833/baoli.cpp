#include <bits/stdc++.h>
using namespace std;

const int COW_CNT = 8;
const int MAXN = 10;

int n;
string order_cow[COW_CNT] = {
    "Beatrice",
    "Belinda",
    "Bella",
    "Bessie",
    "Betsy",
    "Blue",
    "Buttercup",
    "Sue"};

string need_a[MAXN], need_b[MAXN];

int find_pos(string name)
{
    for (int i = 0; i < COW_CNT; i++)
    {
        if (order_cow[i] == name)
        {
            return i;
        }
    }
    return -1;
}

bool check_order()
{
    for (int i = 1; i <= n; i++)
    {
        int pos_a = find_pos(need_a[i]);
        int pos_b = find_pos(need_b[i]);
        if (abs(pos_a - pos_b) != 1)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string t;
        cin >> need_a[i] >> t >> t >> t >> t >> need_b[i];
    }

    do
    {
        if (check_order())
        {
            for (int i = 0; i < COW_CNT; i++)
            {
                cout << order_cow[i] << '\n';
            }
            return 0;
        }
    } while (next_permutation(order_cow, order_cow + COW_CNT));

    return 0;
}