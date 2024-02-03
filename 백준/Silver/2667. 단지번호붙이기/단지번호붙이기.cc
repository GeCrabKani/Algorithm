#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[25][25], chk[25][25];
int xy[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int dfs(int y, int x) {
	int size = 1;
	chk[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int yy = y + xy[i][0], xx = x + xy[i][1];
		if (xx < 0 || yy < 0 || xx >= n || yy >= n) {
			continue;
		}
		if (arr[yy][xx] == 1 && chk[yy][xx] == 0) {
			size += dfs(yy, xx);
		}
	}
	return size;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	vector<int> v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1 && chk[i][j] == 0) {
				v.push_back(dfs(i, j));
			}
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
    return 0;
}	