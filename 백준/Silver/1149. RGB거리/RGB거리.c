#include<stdio.h>

int data[1001][4] = {0};
int min0[1001][4] = {0};

int min(int a, int b){
	if (a > b){
		return b;
	}
	else{
		return a;
	}
}

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			scanf("%d",&data[i][j]);
		}
	}
    min0[2][1] = data[2][1] + min(data[1][2], data[1][3]);
    min0[2][2] = data[2][2] + min(data[1][1], data[1][3]);
	min0[2][3] = data[2][3] + min(data[1][1], data[1][2]);
	for (int i = 3; i <= n; i++) {
		min0[i][1] = data[i][1] + min(min0[i - 1][2], min0[i - 1][3]);
		min0[i][2] = data[i][2] + min(min0[i - 1][1], min0[i - 1][3]);
		min0[i][3] = data[i][3] + min(min0[i - 1][1], min0[i - 1][2]);
	}
	printf("%d", min(min(min0[n][1], min0[n][2]), min0[n][3]));
}