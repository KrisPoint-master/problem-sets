#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int count_g_even(const string &t) {
    int cnt = 0;
    for (int i = 1; i < n; i += 2) {
        if (t[i] == 'G') cnt++;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> s;

    unordered_map<string, int> dist;
    queue<string> q;
    dist[s] = 0;
    q.push(s);

    while (!q.empty()) {
        string cur = q.front(); q.pop();
        int d = dist[cur];
        for (int len = 2; len <= n; len += 2) {
            string nxt = cur;
            reverse(nxt.begin(), nxt.begin() + len);
            if (!dist.count(nxt)) {
                dist[nxt] = d + 1;
                q.push(nxt);
            }
        }
    }

    int max_score = -1, min_steps = INT_MAX;
    for (auto &[state, steps] : dist) {
        int score = count_g_even(state);
        if (score > max_score || (score == max_score && steps < min_steps)) {
            max_score = score;
            min_steps = steps;
        }
    }

    cout << min_steps << endl;
    return 0;
}
