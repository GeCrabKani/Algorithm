#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long n, m, max = -1, start = 0, end, mid, sum;
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	end = v[n - 1];
	while(start <= end) {
		sum = 0;
		mid = (start + end) / 2;
		for (int i = 0; i < n; i++) {
			if (v[i] - mid > 0) sum += v[i] - mid;
		}
		if (sum >= m) {
			start = mid + 1;
			if (mid > max) max = mid;
		} else {
			end = mid - 1;
		}
	}
	cout << max;
	return 0;
}