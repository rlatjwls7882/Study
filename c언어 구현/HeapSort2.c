#include<stdio.h>
#include<stdlib.h>

int arr[101], size;

void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int max(int a, int b) {
    return a<b ? b : a;
}

void downHeap(int i) {
    while(i*2<=size && max(arr[i*2], arr[i*2+1])>arr[i]) {
        if(arr[i*2]>arr[i*2+1]) {
            swap(&arr[i*2], &arr[i]);
            i = i*2;
        } else {
            swap(&arr[i*2+1], &arr[i]);
            i = i*2+1;
        }
    }
}

void heapify(int i) {
    while(i>=1) {
        downHeap(i--);
    }
}

void printHeap() {
    for(int i=1;i<=size;i++) printf(" %d", arr[i]);
    printf("\n");
}

int main() {
    scanf("%d", &size);
    for(int i=1;i<=size;i++) scanf("%d", &arr[i]);
    heapify(size/2);
    printHeap();
}