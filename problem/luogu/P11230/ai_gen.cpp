#include <bits/stdc++.h>
using namespace std;

const int MAXV = 200005;
const int MAXR = 105;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k, q;
        cin >> n >> k >> q;

        vector<vector<int>> seq(n);
        for (int i = 0; i < n; i++) {
            int l;
            cin >> l;
            seq[i].resize(l);
            for (int j = 0; j < l; j++) {
                cin >> seq[i][j];
            }
        }

        int max_r = 0;
        vector<pair<int,int>> queries(q);
        for (int i = 0; i < q; i++) {
            cin >> queries[i].first >> queries[i].second;
            max_r = max(max_r, queries[i].first);
        }

        vector<bitset<MAXR>> reachable(MAXV);
        vector<int> one(MAXV, -1);
        vector<bool> multi(MAXV, false);

        // round 0: value 1 is reachable by "anyone"
        one[1] = -2;
        multi[1] = true;

        for (int r = 1; r <= max_r; r++) {
            vector<int> new_one(MAXV, -1);
            vector<bool> new_multi(MAXV, false);

            for (int i = 0; i < n; i++) {
                int len = seq[i].size();
                vector<bool> start_ok(len, false);
                for (int p = 0; p < len; p++) {
                    int v = seq[i][p];
                    if (one[v] != -1) {
                        start_ok[p] = multi[v] || one[v] != i;
                    }
                }

                int active = 0;
                for (int p = 0; p < len; p++) {
                    if (p - k >= 0 && start_ok[p - k]) {
                        active--;
                    }
                    if (active > 0) {
                        int v = seq[i][p];
                        if (new_one[v] == -1) {
                            new_one[v] = i;
                        } else if (new_one[v] != i) {
                            new_multi[v] = true;
                        }
                    }
                    if (start_ok[p]) {
                        active++;
                    }
                }
            }

            for (int v = 0; v < MAXV; v++) {
                if (new_one[v] != -1) {
                    reachable[v].set(r);
                    one[v] = new_one[v];
                    multi[v] = new_multi[v];
                } else {
                    one[v] = -1;
                    multi[v] = false;
                }
            }
        }

        for (auto [r, c] : queries) {
            cout << (reachable[c].test(r) ? 1 : 0) << '\n';
        }
    }
    return 0;
}
