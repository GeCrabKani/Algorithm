#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, v;
vector<vector<int>> vec(1001);
queue<int> q;
int chkdfs[1001];
int chkbfs[1001];

void dfs(int node) {
	cout << node << " ";
	chkdfs[node] = 1;
	for (int i = 0; i < vec[node].size(); i++) {
		if(!chkdfs[vec[node][i]]) {
			dfs(vec[node][i]);
		}
	}
}

void bfs(int node) {
	queue<int> q;
	q.push(node);
	chkbfs[node] = 1;
	while(!q.empty()) {
		int f = q.front();
		q.pop();
		cout << f << " ";
		for (int i = 0; i < vec[f].size(); i++) {
			if(!chkbfs[vec[f][i]]) {
				chkbfs[vec[f][i]] = 1;
				q.push(vec[f][i]);
			}
		}
	}
}

int main() {
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int x, y;
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		sort(vec[i].begin(), vec[i].end());	
	}
	dfs(v);
	cout << endl;
	bfs(v);
    return 0;
}