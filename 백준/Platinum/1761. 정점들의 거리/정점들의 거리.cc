#include <iostream>
#include <vector>
using namespace std;

#define MAX_NODE 40001
#define MAX_DEPTH 17 // 2^16 > 50000
int parent[MAX_NODE][MAX_DEPTH];
int depth[MAX_NODE];
int dis[MAX_NODE];
bool check[MAX_NODE];
vector<pair<int, int>> tree[MAX_NODE];
int N, M;

void dfs(int node, int parent_node, int level, int distance) {
	depth[node] = level;
	dis[node] = distance;
	parent[node][0] = parent_node;
	for (int i = 1; i < MAX_DEPTH; i++) {
		int temp = parent[node][i - 1];
		parent[node][i] = parent[temp][i - 1];
	}
	for (int i = 0; i < tree[node].size(); i++) {
		int next_node = tree[node][i].first;
		int next_distance = tree[node][i].second;
		if (next_node == parent_node) continue;
		dfs(next_node, node, level + 1, distance + next_distance);
	}
}

int LCA(int u, int v) {
	if (depth[u] > depth[v]) swap(u, v);
	for (int i = MAX_DEPTH - 1; i >= 0; i--)
		if (depth[v] - depth[u] >= (1 << i)) v = parent[v][i];
	if (u == v) return u;
	for (int i = MAX_DEPTH - 1; i >= 0; i--) {
		if (parent[u][i] != parent[v][i]) {
			u = parent[u][i];
			v = parent[v][i];
		}
	}
	return parent[u][0];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		tree[u].push_back({ v, w });
		tree[v].push_back({ u, w });
	}
	dfs(1, 0, 1, 0);
	cin >> M;
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		int lca = LCA(u, v);
		cout << dis[u] + dis[v] - 2 * dis[lca] << "\n";
	}
	return 0;
}