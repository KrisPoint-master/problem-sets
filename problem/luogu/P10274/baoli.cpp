#include <bits/stdc++.h>
using namespace std;

int n, q;

string op[200005];

void init()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> op[i];
    }
}

int get_ans_b(vector<string> &b)
{
    stack<bool> st;

    // for_each(b.begin(), b.end(), [b](auto out){cout << out << " ";}),cout << endl;

    for (int i = 1; i < (int)b.size(); i += 2)
    {
        bool val = (b[i] == "true");
        if (i > 1 && b[i - 1] == "and")
        {
            val = st.top() && val;
            st.pop();
        }
        st.push(val);
    }
    bool ans = false;
    while (!st.empty())
    {
        ans = ans || st.top();
        st.pop();
    }
    return ans;
}

int solve(int l, int r, bool change)
{
    vector<string> b{op, op + 1 + n};
    b.erase(b.begin() + l, b.begin() + r + 1);
    b.insert(b.begin() + l, 1, (change) ? "true" : "false");
    return get_ans_b(b);
}

void work()
{
    string ans = "";
    while (q--)
    {
        int l, r;
        bool target;
        bool ans;
        string tmp;
        cin >> l >> r >> tmp;
        target = (tmp == "true");
        ans = solve(l, r, (tmp == "true") ? 1 : 0);
        if (ans == target)
            putchar('Y');
        else
            putchar('N');
    }
    // cout << ans << '\n';
}

int main(int argc, char const *argv[])
{
    init();
    work();
    return 0;
}
