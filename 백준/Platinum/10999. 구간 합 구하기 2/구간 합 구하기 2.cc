#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<long long> arr;
vector<long long> segtree;
vector<long long> lazy;

// 세그먼트 트리 초기화
long long init(int node, int start, int end) {
	if (start == end) return segtree[node] = arr[start];
	int mid = (start + end) / 2;
	return segtree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

void update_lazy(int node, int start, int end) {
	if (lazy[node] != 0) {
		segtree[node] += (end - start + 1) * lazy[node];
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

// 구간 합 조회
long long sum(int node, int start, int end, int left, int right) {
	update_lazy(node, start, end);
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return segtree[node];
	int mid = (start + end) / 2;
	return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

void update_range(int node, int start, int end, int left, int right, long long diff) {
	update_lazy(node, start, end);
	if (left > end || right < start) return;
	if (left <= start && end <= right) {
		segtree[node] += (end - start + 1) * diff;
		if (start != end) {
			lazy[node * 2] += diff;
			lazy[node * 2 + 1] += diff;
		}
		return;
	}
	int mid = (start + end) / 2;
	update_range(node * 2, start, mid, left, right, diff);
	update_range(node * 2 + 1, mid + 1, end, left, right, diff);
	segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, k, a, b, c;
	long long d;
	cin >> n >> m >> k;
	arr.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	segtree.resize(tree_size);
	lazy.resize(tree_size);
	init(1, 1, n);
	for (int i = 0; i < m + k; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			cin >> d;
			update_range(1, 1, n, b, c, d);
		}
		else if (a == 2) {
			cout << sum(1, 1, n, b, c) << "\n";
		}
	}
	return 0;
}