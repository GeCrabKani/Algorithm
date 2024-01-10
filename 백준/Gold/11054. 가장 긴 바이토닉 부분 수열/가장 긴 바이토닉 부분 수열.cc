#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, answer = 0;
	cin >> n;
	vector<int> v(n);
	vector<int> left(n + 1, 1);
	vector<int> right(n + 1, 1);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (v[i] > v[j] && left[i] <= left[j]) {
				left[i] = left[j] + 1;
			}
		}
	}

	for (int i = n - 2; i >= 0; i--) {
		for (int j = n - 1; j > i; j--) {
			if (v[i] > v[j] && right[i] <= right[j]) {
				right[i] = right[j] + 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		answer = max(left[i] + right[i] - 1, answer);
	}
	cout << answer;
	return 0;
}
