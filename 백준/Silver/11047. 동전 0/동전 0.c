#include<stdio.h>

int main(){
	int n,k,count = 0;
	scanf("%d %d",&n,&k);
	int arr[10];
	for(int i = 0; i < n; i++){
		scanf("%d",&arr[i]);
	}
	for(int i = n - 1; i >= 0; i--){
		while (k >= arr[i]){
			k -= arr[i];
			count ++;
		}
	}
	printf("%d",count);
}
