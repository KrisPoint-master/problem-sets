#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
const int maxe = 100005;
struct Edge
{
    int v, next;
} e[maxe];
int head[maxn], cnt;
int n, m, indeg[maxn], seq[maxn];
void init()
{
    cin >> n >> m;
    cnt = 0;
    memset(head, -1, sizeof(int) * (n + 1));
    memset(indeg, 0, sizeof(int) * (n + 1));

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        e[cnt] = {y, head[x]};
        head[x] = cnt++;
        indeg[y]++;
    }
}
void toposort()
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++)
        if (indeg[i] == 0)
            pq.push(i);

    vector<int> ans;
    while (!pq.empty())
    {
        int u = pq.top();
        pq.pop();
        ans.push_back(u);
        for (int i = head[u]; i != -1; i = e[i].next)
        {
            int v = e[i].v;
            if (--indeg[v] == 0)
                pq.push(v);
        }
    }

    if ((int)ans.size() != n)
    {
        cout << "Impossible!" << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        init();
        toposort();
    }
    return 0;
}