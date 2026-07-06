#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int a[maxn];

int main(int argc, char **argv)
{
    long long n, a, b;
    cin >> n >> a >> b;
    cout << ((n * n > a * b) ? "Alice" : "Bob");
    return 0;
}