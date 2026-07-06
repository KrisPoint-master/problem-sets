#include <bits/stdc++.h>
using namespace std;

struct shangpin {
    int p;
    int d;
};

bool cmp(shangpin a, shangpin b) {
    return a.p > b.p;
}

int tree[10005];

int find(int x) {
    if (tree[x] == x) return x;
    return tree[x] = find(tree[x]);
}

shangpin sp[100006];

int main() {
    int n;
    while (cin >> n) {
        int max_d = 0;
        
        for (int i = 1; i <= n; i++) {
            cin >> sp[i].p >> sp[i].d;
            if (sp[i].d > max_d) {
                max_d = sp[i].d;
            }
        }

        sort(sp+1,sp+n+1, cmp);

        for (int i = 0; i <= max_d; i++) {
            tree[i] = i;
        }

        int tot = 0;

        for (int i = 1; i <= n; i++) {
            int d = find(sp[i].d);
            
            if (d > 0) {
                tot += sp[i].p;
                tree[d] = d - 1;
            }
        }

        cout << tot << endl;
    }
    return 0;
}