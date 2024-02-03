#include<stdio.h>

int main(){
	int a;
	scanf("%d",&a);
	for (int i = 0; i < a; i++){
		int count1 = 0,count2 = 0, count3 = 0;
		char arr[51];
		scanf("%s",arr);
		if (arr[0] == ')'){
			printf("NO\n");
			count3 ++;
		}
		else {
			for (int j = 0; j < strlen(arr); j++){
				if (arr[j] == '('){
					count1 ++;
				}
				else {
					count2 ++;
				}
				if (count2 > count1){
					printf("NO\n");
					count3 ++;
					break;
				}
			}
		}
		if (count1 == count2 && count3 == 0){
			printf("YES\n");
		}
		else if (count3 == 0){
			printf("NO\n");
		}
	}
}