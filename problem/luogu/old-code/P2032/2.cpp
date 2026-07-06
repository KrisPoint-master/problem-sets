#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 5;
int a[maxn];
int n, k;
template <typename T>
struct que
{
    deque<T> dq;
    void into(T x)
    {
        while (!dq.empty() && a[x] > a[dq.back()])
            dq.pop_back();
        while (!dq.empty() && x - dq.front() >= k)
            dq.pop_front();
        dq.push_back(x);
    }
    void pop1()
    {
        dq.pop_back();
    }
    void pop2()
    {
        dq.pop_front();
    }
    bool empty()
    {
        return dq.empty();
    }
    bool size()
    {
        return dq.size();
    }
};

int main(int argc, char const *argv[])
{
    que<int> q;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        q.into(i);
        if (i >= k)
            cout << a[q.dq.front()] << endl;
    }

    return 0;
}
