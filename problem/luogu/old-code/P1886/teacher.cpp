#include <iostream>
using namespace std;
const int maxn = 1e7 + 5;
int n, m;
int a[maxn];

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

myqueue q1;
myqueue pos; // 存位置

// 排除 比自己大的且比自己老的
template <typename F>
void push1(int a, int _pos, F cmp)
{
    while (!q1.empty() && cmp(q1.back(), a))
    {
        q1.pop_back();
        pos.pop_back();
    }
    q1.push(a);
    pos.push(_pos);
}

// 删除过时的元素
void pop_intime(int now_pos)
{
    while (!pos.empty() && pos.front() < now_pos - m + 1)
    {
        pos.pop();
        q1.pop();
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= m - 1; i++)
    {
        push1(a[i], i, [](int a, int b)
              { return a >= b; });
    }
    for (int i = m; i <= n; i++)
    {
        push1(a[i], i, [](int a, int b)
              { return a >= b; });
        pop_intime(i);
        cout << q1.front() << " ";
    }
    cout << endl;

    q1.clear();
    pos.clear();

    for (int i = 1; i <= m - 1; i++)
    {
        push1(a[i], i, [](int a, int b)
              { return a <= b; });
    }
    for (int i = m; i <= n; i++)
    {
        push1(a[i], i, [](int a, int b)
              { return a <= b; });
        pop_intime(i);
        cout << q1.front() << " ";
    }
    cout << endl;

    return 0;
}