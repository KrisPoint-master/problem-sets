#include <bits/stdc++.h>
using namespace std;

mt19937 rng((unsigned)chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

int main() {
    int n = rnd(1, 6);
    int x = rnd(1, 10);
    cout << n << " " << x << "\n";
    for (int i = 1; i <= n; i++) {
        cout << rnd(0, 20) << " \n"[i == n];
    }
    return 0;
}
