#include<stdio.h>
#include<stdlib.h>

void init(int* arr, int M) {
    for(int i=0;i<M;i++) arr[i]=0;
}

int h(int x, int M) { return x%M; }
int h2(int x, int q) { return q - x%q; }

void insert(int *arr, int val, int M, int q) {
    int hVal = h(val, M);
    if(arr[hVal]) {
        int move = h2(val, q);
        while(arr[hVal]) {
            hVal = (hVal+move)%M;
            printf("C");
        }
    }
    arr[hVal]=val;
    printf("%d\n", hVal);
}

void select(int *arr, int val, int M, int q) {
    int hVal = h(val, M);
    int move = h2(val, q);
    while(arr[hVal]) {
        if(arr[hVal] == val) {
            printf("%d %d\n", hVal, arr[hVal]);
            return;
        }
        hVal = (hVal+move)%M;
    }
    printf("-1\n");
}

void print(int *arr, int M) {
    for(int i=0;i<M;i++) printf(" %d", arr[i]);
    printf("\n");
}

int main(void) {
    int M, n, q; scanf("%d%d%d%*c", &M, &n, &q);
    int *arr = (int*)malloc(sizeof(int)*M);
    init(arr, M);

    while(1) {
        char ch; scanf("%c%*c", &ch);
        if(ch=='e') break;
        if(ch=='p') {
            print(arr, M);
            continue;
        }
        int val; scanf("%d%*c", &val);
        if(ch=='i') insert(arr, val, M, q);
        else select(arr, val, M, q);
    }
    print(arr, M);
    free(arr);
}