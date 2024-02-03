#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int arr[50][50], chk[50][50];
int xy[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int dfs(int y, int x) {
	int size = 1;
	chk[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int yy = y + xy[i][0], xx = x + xy[i][1];
		if (xx < 0 || yy < 0 || xx >= m || yy >= n) {
			continue;
		}
		if (arr[yy][xx] == 1 && chk[yy][xx] == 0) {
			size += dfs(yy, xx);
		}
	}
	return size;
}

int main() {
	int t, k;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> m >> n >> k;
		for (int j = 0; j < k; j++) {
			int x, y;
			cin >> x >> y;
			arr[y][x] = 1;
		}
		vector<int> v;
		for (int j = 0; j < n; j++) {
			for (int l = 0; l < m; l++) {
				if (arr[j][l] == 1 && chk[j][l] == 0) {
					v.push_back(dfs(j, l));
				}
			}
		}
		cout << v.size() << endl;
		for (int j = 0; j < 50; j++) {
			for (int l = 0; l < 50; l++) {
				arr[j][l] = 0;
				chk[j][l] = 0;
			}
		}
	}
    return 0;
}	