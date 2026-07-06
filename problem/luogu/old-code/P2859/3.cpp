#include <bits/stdc++.h>
using namespace std;

struct Cow
{
    int start, end, id;
};

bool cmpStart(const Cow &a, const Cow &b)
{
    return a.start < b.start;
}

int n;
vector<Cow> cows(n);
int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> cows[i].start >> cows[i].end;
        cows[i].id = i;
    }

    sort(cows.begin(), cows.end(), cmpStart);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> stall_assignment(n);
    int stall_count = 0;

    for (int i = 0; i < n; i++)
    {
        int start = cows[i].start;
        int end = cows[i].end;
        int cow_id = cows[i].id;

        if (pq.empty() || pq.top().first >= start)
        {
            stall_count++;
            pq.push({end, stall_count});
            stall_assignment[cow_id] = stall_count;
        }
        else
        {
            int stall_id = pq.top().second;
            pq.pop();
            pq.push({end, stall_id});
            stall_assignment[cow_id] = stall_id;
        }
    }

    cout << stall_count << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << stall_assignment[i] << "\n";
    }

    return 0;
}
