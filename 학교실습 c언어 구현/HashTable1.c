#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    struct node *next;
    int val;
} node;

void init(node* arr, int M) {
    for(int i=0;i<M;i++) arr[i].next=NULL;
}

int h(int x, int M) {
    return x%M;
}

void print(node *arr, int M) {
    for(int i=0;i<M;i++) {
        if(arr[i].next) {
            node *cur = arr[i].next;
            while(1) {
                printf(" %d", cur->val);
                if(!cur->next) break;
                cur = cur->next;
            }
        }
    }
    printf("\n");
}

void insert(node *arr, int val, int M) {
    int hVal = h(val, M);
    node *n = (node*)malloc(sizeof(node));
    n->next=NULL;
    n->val=val;
    if(!arr[hVal].next) {
        arr[hVal].next = n;
    } else {
        n->next = arr[hVal].next;
        arr[hVal].next = n;
    }
}

int search(node *n /* list의 head부분 */, int val, char mod) {
    int idx=1;
    while(n->next) {
        if(n->next->val == val) {
            if(mod=='d') n->next = n->next->next;
            return idx;
        }
        n = n->next;
        idx++;
    }
    return 0;
}

void selectAndDelete(node *arr, int val, int M, char mod) {
    int hVal = h(val, M);
    printf("%d\n", search(&arr[hVal], val, mod));
}

int main(void) {
    int M; scanf("%d%*c", &M);
    node *arr = (node*)malloc(sizeof(node)*M);
    init(arr, M);

    while(1) {
        char ch; scanf("%c%*c", &ch);
        if(ch=='i') {
            int val; scanf("%d%*c", &val);
            insert(arr, val, M);
        } else if(ch=='s' || ch=='d') {
            int val; scanf("%d%*c", &val);
            selectAndDelete(arr, val, M, ch);
        } else if(ch=='p') {
            print(arr, M);
        } else {
            break;
        }
    }
    free(arr);
}