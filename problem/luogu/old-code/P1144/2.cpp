#include <cstdio>
#include <cstring>
#include <queue> // 引入 STL 队列头文件

using namespace std; // 使用 std 命名空间

int head[100];
bool vis[100] = {0};

int edge_count = 0; // 原 size 与关键字冲突，建议改名
struct edge
{
    int u, v, w, next;
} E[200]; // 注意：无向图边数要开两倍

int n, m;

void addEdge(int x, int y, int z)
{
    edge_count++;
    E[edge_count].u = x;
    E[edge_count].v = y;
    E[edge_count].w = z;
    E[edge_count].next = head[x];
    head[x] = edge_count;
}

void bfs(int start)
{
    queue<int> q; // 定义 STL 队列

    q.push(start); // 入队
    vis[start] = true;

    while (!q.empty())
    {                      // 只要队列不为空
        int t = q.front(); // 取出队头元素
        q.pop();           // 弹出队头

        printf("%d ", t);

        // 遍历邻接边
        for (int i = head[t]; i != -1; i = E[i].next)
        {
            int now = E[i].v;
            if (!vis[now])
            {
                q.push(now);     // 入队
                vis[now] = true; // 标记已访问
            }
        }
    }
}

int main()
{
    memset(head, -1, sizeof(head));

    // 假设输入节点数 n 和边数 m
    if (scanf("%d%d", &n, &m) != 2)
        return 0;

    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        addEdge(x, y, z);
        addEdge(y, x, z); // 无向图
    }

    // 从起点 0 开始 BFS
    bfs(0);

    return 0;
}