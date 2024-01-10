#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

vector<int> arr;
vector<int> segtreeMax, segtreeMin;


int initMin(int node, int start, int end) {
	if (start == end) return segtreeMin[node] = arr[start];
	int mid = (start + end) / 2;
	return segtreeMin[node] = min(initMin(node * 2, start, mid), initMin(node * 2 + 1, mid + 1, end));
}

int minValue(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return INT_MAX;
	if (left <= start && right >= end) return segtreeMin[node];
	int mid = (start + end) / 2;
	return min(minValue(node * 2, start, mid, left, right), minValue(node * 2 + 1, mid + 1, end, left, right));
}

int initMax(int node, int start, int end) {
	if (start == end) return segtreeMax[node] = arr[start];
	int mid = (start + end) / 2;
	return segtreeMax[node] = max(initMax(node * 2, start, mid), initMax(node * 2 + 1, mid + 1, end));
}

int maxValue(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && right >= end) return segtreeMax[node];
	int mid = (start + end) / 2;
	return max(maxValue(node * 2, start, mid, left, right), maxValue(node * 2 + 1, mid + 1, end, left, right));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, a, b;
	cin >> n >> m;
	arr.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	segtreeMin.resize(tree_size);
	segtreeMax.resize(tree_size);
	initMin(1, 1, n);
	initMax(1, 1, n);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cout << minValue(1, 1, n, a, b) << " " << maxValue(1, 1, n, a, b) << "\n";
	}
	return 0;
}