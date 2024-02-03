#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	long long arr[100] = {0};
	arr[0] = 1;
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 2;
	arr[4] = 2;
	for (int i = 5; i < 100; i++) {
			arr[i] = arr[i - 1] + arr[i - 5];
		}
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		cout << arr[a - 1] << endl;
	}
	return 0;
}