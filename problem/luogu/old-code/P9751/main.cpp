#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
const int maxe = 1e5 + 5;

struct linkList
{
    typedef struct
    {
        int u, v, w, next;
    } edge;
    edge e[maxe];
    int h[maxn], edge_cnt = 0;
    linkList()
    {
        edge_cnt = 0;
        memset(h, -1, sizeof(h));
    }
    void add(int u, int v, int w = 0)
    {
        e[edge_cnt] = {u, v, w, h[u]};
        h[u] = edge_cnt++;
    }
} e;

int main(int argc, char const *argv[])
{

    return 0;
}
