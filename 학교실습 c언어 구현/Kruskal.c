#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct node {
    struct node *parent;
    int n;
} node;

typedef struct edge {
    node *a, *b;
    int cost;
} edge;

typedef struct priority_queue {
    edge *heap;
    int size;
} priority_queue;

void swap(edge *a, edge *b) {
    edge tmp = *a;
    *a = *b;
    *b = tmp;
}

void pqInsert(priority_queue *pq, edge *e) {
    pq->size++;
    pq->heap[pq->size]=*e;

    int idx=pq->size;
    while(idx>1) {
        if(pq->heap[idx].cost < pq->heap[idx/2].cost) {
            swap(&pq->heap[idx], &pq->heap[idx/2]);
            idx/=2;
        } else {
            break;
        }
    }
}

edge pop(priority_queue *pq) {
    swap(&pq->heap[1], &pq->heap[pq->size]);
    pq->size--;

    int idx=1;
    while(1) {
        if(idx*2+1<=pq->size && pq->heap[idx*2+1].cost<pq->heap[idx*2].cost && pq->heap[idx*2+1].cost < pq->heap[idx].cost) {
            swap(&pq->heap[idx], &pq->heap[idx*2+1]);
            idx = idx*2+1;
        } else if(idx*2<=pq->size && pq->heap[idx*2].cost < pq->heap[idx].cost) {
            swap(&pq->heap[idx], &pq->heap[idx*2]);
            idx*=2;
        } else {
            break;
        }
    }
    return pq->heap[pq->size+1];
}

node* find(node *n) {
    if(n->parent==n) return n;
    return n->parent = find(n->parent);
}

int merge(node *a, node *b) {
    node *aP = find(a);
    node *bP = find(b);
    if(aP==bP) return 0;
    if(aP<bP) bP->parent=aP;
    else aP->parent=bP;
    return 1;
}

int main(void) {
    int N, M; scanf("%d %d", &N, &M);
    node *n = (node*)malloc(sizeof(node)*N);
    edge *e = (edge*)malloc(sizeof(edge)*M);
    for(int i=0;i<N;i++) n[i].parent=&n[i], n[i].n=i;

    // Priority_Queue Init
    priority_queue *pq = (priority_queue*)malloc(sizeof(priority_queue));
    pq->heap = (edge*)malloc(sizeof(edge)*(M+1));
    pq->size=0;

    for(int i=0;i<M;i++) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        e[i].a = &n[a-1];
        e[i].b = &n[b-1];
        e[i].cost = c;
        pqInsert(pq, &e[i]);
    }

    // Kruskal
    int sum=0;
    while(pq->size) {
        edge cur = pop(pq);
        if(merge(cur.a, cur.b)) {
            sum += cur.cost;
            printf(" %d", cur.cost);
        }
    }
    printf("\n%d", sum);

    // Free
    free(pq->heap);
    free(pq);
    free(e);
    free(n);
}