#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
template <typename T = int, int siz = maxn>
struct myqueue
{
    T a[siz + 5];
    // tail 指向最后一个元素后面一个位置
    // head 指向第一个元素
    int head = 0, tail = 0;

    void clear() { head = tail = 0; }

    void push(T b) { a[tail++] = b; }

    void pop() { head++; }
    void pop_back() { tail--; }

    T front() { return a[head]; }
    T back() { return a[tail - 1]; }

    bool empty() { return head == tail; }

    int size() { return tail - head; }
};
int main()
{
    int m, n, t, ans = 0;
    cin >> m >> n;
    vector<int> v;
    while (cin >> t)
    {
        if (find(v.begin(), v.end(), t) == v.end())
        {
            v.push_back(t);
            ++ans;
        }
        if (v.size() > m)
            v.erase(v.begin());
    }
    cout << ans << endl;
    return 0;
}