#include<stdio.h>
#include<stdlib.h>

void init(int* arr, int M) {
    for(int i=0;i<M;i++) arr[i]=0;
}

int h(int x, int M) {
    return x%M;
}

void insert(int *arr, int val, int M) {
    int hVal = h(val, M);
    while(arr[hVal]) {
        hVal = (hVal+1)%M;
        printf("C");
    }
    arr[hVal]=val;
    printf("%d\n", hVal);
}

void select(int *arr, int val, int M) {
    int hVal = h(val, M);
    while(arr[hVal]) {
        if(arr[hVal] == val) {
            printf("%d %d\n", hVal, arr[hVal]);
            return;
        }
        hVal = (hVal+1)%M;
    }
    printf("-1\n");
}

int main(void) {
    int M, n; scanf("%d%d%*c", &M, &n);
    int *arr = (int*)malloc(sizeof(int)*M);
    init(arr, M);

    while(1) {
        char ch; scanf("%c%*c", &ch);
        if(ch=='e') break;
        int val; scanf("%d%*c", &val);
        if(ch=='i') insert(arr, val, M);
        else select(arr, val, M);
    }
    free(arr);
}