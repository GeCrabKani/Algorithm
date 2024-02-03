#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	vector<int> lis;
	for (int i = 0; i < n; i++) {

		auto it = lower_bound(lis.begin(), lis.end(), v[i]);

		if (it == lis.end()) {
			lis.push_back(v[i]);
		}
		else {
			*it = v[i];
		}
	}

	cout << lis.size();

	return 0;
}