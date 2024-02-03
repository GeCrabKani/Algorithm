#include <iostream>
#include <vector>
using namespace std;

int main () {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, cnt = 1;
	cin >> n;
	vector<int> v(n), dp(n, 1);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (v[i] > v[j]) dp[i] = max(dp[j] + 1, dp[i]);
			if (dp[i] > cnt) cnt = dp[i];
		}
	}
	cout << cnt;
	return 0;
}