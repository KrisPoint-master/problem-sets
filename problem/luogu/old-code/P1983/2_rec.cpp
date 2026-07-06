#include <bits/stdc++.h>
using namespace std;

/*
 * 公交车换乘问题：求最多能乘坐多少辆公交车
 * 建模：DAG 上求最长路径
 */

#define MAXN 1005
#define MAXE 1000005

/* 邻接表 */
struct adj_list {
	struct edge {
		int v;
		int next;
	} e[MAXE];
	int head[MAXN];
	int edge_cnt;

	adj_list(void)
	{
		edge_cnt = 0;
		memset(head, -1, sizeof(head));
	}

	void add_edge(int u, int v)
	{
		e[edge_cnt].v = v;
		e[edge_cnt].next = head[u];
		head[u] = edge_cnt++;
	}
} g;

/* 全局变量 */
int n, m;
int indeg[MAXN];
int stops[MAXN];
bool is_stop[MAXN];
bool edge_added[MAXN][MAXN];
int depth[MAXN];

/* 拓扑排序 + 求最长路径
 * 状态转移: depth[v] = max(depth[v], depth[u] + 1)
 */
static void topo_sort(void)
{
	int u, v, i;
	queue<int> q;

	/* 初始化: 入度为0的点入队, depth = 1 */
	for (i = 1; i <= n; i++) {
		if (indeg[i] == 0) {
			q.push(i);
			depth[i] = 1;
		}
	}

	/* BFS 拓扑排序 */
	while (!q.empty()) {
		u = q.front();
		q.pop();

		for (i = g.head[u]; i != -1; i = g.e[i].next) {
			v = g.e[i].v;
			depth[v] = max(depth[v], depth[u] + 1);

			if (--indeg[v] == 0)
				q.push(v);
		}
	}
}

/* 为当前公交车构建边
 * 区间 [first, last] 内的非停靠站 p -> 所有停靠站
 */
static void build_edges(int k)
{
	int first = stops[1];
	int last = stops[k];
	int p, j, stop;

	for (p = first; p <= last; p++) {
		if (is_stop[p])
			continue;

		for (j = 1; j <= k; j++) {
			stop = stops[j];
			if (!edge_added[p][stop]) {
				g.add_edge(p, stop);
				indeg[stop]++;
				edge_added[p][stop] = true;
			}
		}
	}
}

int main(void)
{
	int i, j, k;
	int ans;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (i = 1; i <= m; i++) {
		cin >> k;

		/* 读取停靠站并标记 */
		for (j = 1; j <= k; j++) {
			cin >> stops[j];
			is_stop[stops[j]] = true;
		}

		/* 构建图中的边 */
		build_edges(k);

		/* 重置 is_stop 数组，为下一辆车准备 */
		for (j = 1; j <= k; j++)
			is_stop[stops[j]] = false;
	}

	topo_sort();

	/* 统计答案 */
	ans = 0;
	for (i = 1; i <= n; i++)
		ans = max(ans, depth[i]);

	cout << ans << "\n";
	return 0;
}
