#include <iostream>
#include <algorithm>
using namespace std;

int main () {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> v, tmp;
	for (int i = 1; i <= n; i++) {
		v.push_back(i);
	}
	for (int i = 0; i < m; i++) {
		tmp.push_back(0);
	}
	for (int i = 0; i < n - m; i++) {
		tmp.push_back(1);
	}
	do {
		for (int i = 0; i < n; i++) {
			if (tmp[i] == 0) cout << v[i] << " ";
		}
		cout << "\n";
	} while (next_permutation(tmp.begin(), tmp.end()));
	return 0;
}