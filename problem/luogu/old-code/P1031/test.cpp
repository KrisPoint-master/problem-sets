#include <bits/stdc++.h>
using namespace std;

int n, sum, ave, cnt1, pos, ans = INT32_MAX;
int a[100005], b[100005], b2[100005];

struct node
{
    int data;
    node *next;
    node *prev;
} nodes[100005];

void init()
{
    nodes[0].prev = NULL;
    nodes[0].next = &nodes[1];
    nodes[0].data = NULL;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    ave = sum / n;
    for (int i = 1; i <= n; i++)
    {
        b[i] = a[i] - ave;
    }
    // 把B数组的内容存入链表
    for (int i = 1; i <= n; i++)
    {
        nodes[i].data = b[i];
        nodes[i].next = &nodes[i + 1];
        nodes[i].prev = &nodes[i - 1];
    }
    nodes[n + 1].next = NULL;
    nodes[n + 1].prev = &nodes[n];
    nodes[n + 1].data = NULL;
}

void reinit()
{
    for (int i = 1; i <= n; i++)
    {
        nodes[i].data = b[i];
        nodes[i].next = &nodes[i + 1];
        nodes[i].prev = &nodes[i - 1];
    }
    nodes[n].next = &nodes[1];
}

int main(int argc, char const *argv[])
{
    int l = 1;
    init();
    reinit();
    for (int l = 1; l <= n; l++)
    {
        int k = l;
        for (node pos = nodes[l++]; l <= n; pos = *(pos.next), l++)
        {
            if (pos.data != 0)
            {
                // b[i + 1] += b[i];
                pos.next->data += pos.data;
                pos.data = 0;
                cnt1++;
            }
        }
        ans = min(ans, cnt1);
        cnt1 = 0;
        l = k;
        reinit();
    }
    cout << ans << endl;
    return 0;
}
