#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n, ans = 0;
int arr[15];

bool check(int level) {
	for (int i = 0; i < level; i++) {
		if (arr[i] == arr[level] || abs(arr[i] - arr[level]) == level - i) return false;
	}
	return true;
}

void nqueen(int num) {
	if (num == n) ans++;
	else {
		for (int i = 0; i < n; i++) {
			arr[num] = i;
			if (check(num)) nqueen(num + 1);
		}
	}
}

int main () {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	nqueen(0);
	cout << ans;
	return 0;
}