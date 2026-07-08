#include <bits/stdc++.h>
using namespace std;

int n, a[55], L, R;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> L >> R;

    int sum = 0, need = 0, give = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (a[i] < L) need += L - a[i];
        if (a[i] > R) give += a[i] - R;
    }

    if (sum < n * L || sum > n * R) {
        cout << -1 << endl;
    } else {
        cout << max(need, give) << endl;
    }

    return 0;
}
