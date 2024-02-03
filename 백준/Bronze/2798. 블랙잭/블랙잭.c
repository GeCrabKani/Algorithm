#include <stdio.h>

int max(int a, int b){
	if(a > b){
		return a;
	}
	else {
		return b;
	}
}

int main(){
	int a, b;
	int arr[101];
	scanf("%d %d", &a, &b);
	int max0 = 0;
	for (int i = 1; i <= a; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i <= a - 2; i++) {
		for (int j = i + 1; j <= a - 1; j++) {
			for (int k = j + 1; k <= a; k++) {
				if (arr[i] + arr[j] + arr[k] <= b) {
					max0 = max(max0, arr[i] + arr[j] + arr[k]);
				}
			}
		}
	}
	printf("%d", max0);
}
