#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> v(n + 1), dp(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	dp[1] = v[1];
	dp[2] = v[2] + v[1];
	for (int i = 3; i <= n; i++) {
		dp[i] = max(v[i] + v[i - 1] + dp[i - 3], v[i] + dp[i - 2]);
	}
	cout << dp[n];
	return 0;
}
