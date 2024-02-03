#include <iostream>
using namespace std;

int main() {
	int n, min = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int sum = 0, a = n - i;
		sum += a;
		while (a > 0) {
			sum += a % 10;
			a /= 10;
		}
		if (sum == n) {
			min = n - i;
		}
	}
	cout << min;
	return 0;
}