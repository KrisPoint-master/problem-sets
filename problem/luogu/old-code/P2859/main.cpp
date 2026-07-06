#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;

int n;
struct cow
{
    int id;
    int l, r;
} c[maxn];

struct compare
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.first > b.first; // 定义最小堆
    }
};

bool cmp(cow a, cow b)
{
    return a.l < b.l;
}

int temp[maxn];
int maxr;
std::priority_queue<pair<int, int>, std::vector<pair<int, int>>, compare> pq;
void sovle1()
{
    int ans1 = INT32_MIN;
    for (int i = 1; i <= n; i++)
    {
        temp[c[i].l]++;
        temp[c[i].r + 1]--;
    }
    for (int i = 1; i <= maxr + 1; i++)
    {
        temp[i] += temp[i - 1];
        ans1 = max(ans1, temp[i]);
    }
    cout << ans1 << endl;
}
int ans[maxn];

void sovle2()
{
    int stall_cnt = 0;

    for (int i = 1; i <= n; i++)
    {
        if (pq.empty() || pq.top().first >= c[i].l)
        {
            stall_cnt++;
            pq.push(make_pair(c[i].r, stall_cnt));
            ans[c[i].id] = stall_cnt;
        }
        else
        {
            int stall_id = pq.top().second;
            pq.pop();
            pq.push(make_pair(c[i].r, stall_id));
            ans[c[i].id] = stall_id;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << endl;
    }
}

int main(int argc, char **argv)
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        c[i].id = i;
        cin >> c[i].l >> c[i].r;
        maxr = max(maxr, c[i].r);
    }
    sovle1();
    sort(c + 1, c + 1 + n, cmp);
    sovle2();

    return 0;
}