#include <bits/stdc++.h>
using namespace std;

int n, d;
vector<long long> h;
vector<int> best_assign;
long long best_min = -1;

void dfs(int idx, int min_day, vector<long long>& day_sum, vector<int>& assign) {
    if (idx == n) {
        long long start = 0;
        long long mn = LLONG_MAX;
        for (int day = 0; day < d; day++) {
            long long end_happy = start + day_sum[day];
            mn = min(mn, end_happy);
            start = end_happy / 2;
        }
        if (mn > best_min) {
            best_min = mn;
            best_assign = assign;
        }
        return;
    }
    for (int day = min_day; day < d; day++) {
        assign[idx] = day;
        day_sum[day] += h[idx];
        dfs(idx + 1, day, day_sum, assign);
        day_sum[day] -= h[idx];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> d;
    h.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    vector<long long> day_sum(d, 0);
    vector<int> assign(n);

    dfs(0, 0, day_sum, assign);

    cout << best_min << "\n";
    for (int i = 0; i < n; i++) {
        cout << best_assign[i] + 1 << "\n";
    }

    return 0;
}
