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

	vector<int> lis, trace(n, -1);
	for (int i = 0; i < n; i++) {

		auto it = lower_bound(lis.begin(), lis.end(), v[i]);
        
        int idx = it - lis.begin();

		if (it == lis.end()) {
			lis.push_back(v[i]);
		}
		else {
			*it = v[i];
		}
        trace[i] = idx;
	}

	cout << lis.size() << endl;

	vector<int> ans;
    for (int i = n - 1, j = lis.size() - 1; i >= 0; i--) {
        if (trace[i] == j) {
            ans.push_back(v[i]);
            j--;
        }
    }

    reverse(ans.begin(), ans.end());

    for (int a : ans) {
        cout << a << ' ';
    }

	return 0;
}