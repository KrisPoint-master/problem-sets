#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    if (2 * n <= m) {
        cout << 0 << '\n';
    } else {
        cout << 2 * (2 * n - m) << '\n';
    }
    return 0;
}
