#include <iostream>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b, c = 1;
		scanf("%d %d", &a, &b);
		for (int j = 1; j <= a; j++) {
			c = c * (b - j + 1) / j;
		}
		printf("%d\n", c);
	}
}