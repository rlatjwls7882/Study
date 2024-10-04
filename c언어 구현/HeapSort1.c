#include<stdio.h>
#include<stdlib.h>

int arr[101], size=0;

void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int max(int a, int b) {
    return a<b ? b : a;
}

void upHeap(int i) {
    while(i>1 && arr[i]>arr[i/2]) {
        swap(&arr[i], &arr[i/2]);
        i/=2;
    }
}

void downHeap(int i) {
    while(i*2<=size && max(arr[i*2], arr[i*2+1])>arr[i]) {
        if(arr[i*2]>arr[i*2+1]) {
            swap(&arr[i], &arr[i*2]);
            i = i*2;
        } else {
            swap(&arr[i], &arr[i*2+1]);
            i = i*2+1;
        }
    }
}

void insertItem(int key) {
    arr[++size]=key;
    upHeap(size);
}

int removeMax() {
    int ret = arr[1];
    arr[1]=arr[size];
    size--;
    downHeap(1);
    return ret;
}

void printHeap() {
    for(int i=1;i<=size;i++) printf(" %d", arr[i]);
    printf("\n");
}

int main() {
    while(1) {
        char ch, tmp; scanf("%c%c", &ch, &tmp);
        if(ch=='i') {
            int v; scanf("%d%c", &v, &tmp);
            printf("0\n");
            insertItem(v);
        } else if(ch=='d') {
            printf("%d\n", removeMax());
        } else if(ch=='p') {
            printHeap();
        } else {
            break;
        }
    }
}