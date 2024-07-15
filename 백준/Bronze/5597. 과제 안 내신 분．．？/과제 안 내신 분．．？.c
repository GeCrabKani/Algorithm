#include<stdio.h>
int main() {
	int a,b=0;
	int arr[30] = { 0, };
	for (int i = 0; i < 28; i++) {
		scanf("%d",&a);
		arr[a - 1] = 1;
	}
	for (int i = 0; i < 30; i++) {
		if (arr[i] != 1) {
			printf("%d\n",i+1);
			b = b + 1;
			if (b == 2) break;
		}
	}
}