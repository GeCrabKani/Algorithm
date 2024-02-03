#include <stdio.h>

void quickSort(int *data, int start, int end) {
	if (start >= end) { 
		return; 
	}
	
	int key = start; 
	int i = start + 1;
	int j = end;
	int temp;
	
	while(i <= j) { 
		while(data[i] <= data[key]) { 
			i++;	
		}
		while(data[j] >= data[key] && j > start) {
			j--; 
		}
		if (i > j) { 
			temp = data[j];
			data[j] = data[key];
			data[key] = temp; 
		} else {
			temp = data[j];
			data[j] = data[i];
			data[i] = temp;
		}
	}
	
	quickSort(data, start, j - 1);
	quickSort(data, j + 1, end);
}

int main(){
	int n, sum = 0;
	scanf("%d", &n);
	int arr[1000];
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	quickSort(arr, 0, n - 1);
	for (int i = 0; i < n; i++) {
		sum += arr[i] * (n - i);
	}
	printf("%d", sum);
}