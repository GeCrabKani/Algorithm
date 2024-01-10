#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> vn(n), vk(k + 1, 1e9);
	for (int i = 0; i < n; i++) {
		cin >> vn[i];
	}

	vk[0] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = vn[i]; j <= k; j++) {
			vk[j] = min(vk[j - vn[i]] + 1, vk[j]);
		}
	}
	if (vk[k] == 1e9) {
		cout << -1;
	}
	else {
		cout << vk[k];
	}
    return 0;
}