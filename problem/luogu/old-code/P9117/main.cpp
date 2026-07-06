#include <bits/stdc++.h>
using namespace std;
    
struct Node {
    int color = 0;
    int time = 0;
};

Node rows[100005];
Node cols[100005];

void work() {
    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 1; i <= n; i++) {
        rows[i].color = 0;
        rows[i].time = 0;
    }
    for (int j = 1; j <= m; j++) {
        cols[j].color = 0;
        cols[j].time = 0;
    }

    for (int i = 1; i <= q; i++) {
        int opt, x, c;
        cin >> opt >> x >> c;
        if (opt == 0) {
            rows[x] = {c, i};
        } else {
            cols[x] = {c, i};
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (rows[i].time > cols[j].time) {
                cout << rows[i].color << (j == m ? "" : " ");
            } else {
                cout << cols[j].color << (j == m ? "" : " ");
            }
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}