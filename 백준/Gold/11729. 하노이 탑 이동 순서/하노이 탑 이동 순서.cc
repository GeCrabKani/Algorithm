#include <iostream>
using namespace std;

void hanoi(int a, int b, int c) {
	if (a != 0) {
		hanoi(a - 1, b, 6 - b - c);
		printf("%d %d\n", b, c);
		hanoi(a - 1, 6 - b - c, c);
	}
}

int main() {
	int n;
	cin >> n;
	cout << (1 << n) - 1 << endl;
	hanoi(n, 1, 3);
	return 0;
}