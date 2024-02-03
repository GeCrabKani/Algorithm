#include <stdio.h>

int arr[501][501];
int arr1[501][501];
int tri(int a, int b, int c);
int max(int a, int b);

int main(){
    int a;
    scanf("%d",&a);
    for (int i = 0; i < 501; i ++){
        for (int j = 0; j <501; j++){
            arr1[i][j] = -1;
        }
    }
    for (int i = 0; i < a; i++){
        for (int j = 0; j <= i; j++){
            scanf("%d",&arr[i][j]);
        }
    }
    arr1[0][0] = tri(a,0,0);
    printf("%d",arr1[0][0]);
}

int tri(int a, int b, int c){
    int tmp;
    if (b == a - 1){
        return arr[b][c];
    }
    else {
        if (arr1[b][c] == -1){
            tmp = arr[b][c] + max(tri(a, b + 1, c) , tri(a, b + 1, c + 1));
            arr1[b][c] = tmp;
            return tmp;
        }
        else {
            return arr1[b][c];
        }
    }
}

int max(int a, int b){
    if (a > b){
        return a;
    }
    else {
        return b;
    }
}