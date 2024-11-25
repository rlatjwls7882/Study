#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#define INF 1000000000

/********** Graph ***********/
typedef struct list {
    struct list *next;
    struct edge *e;
} list;

typedef struct node {
    list *list;
    int nodeNum, toCost;
} node;

typedef struct edge {
    node *a, *b;
    int cost;
} edge;

void insert(node *n, edge *e) {
    list *l = (list*)malloc(sizeof(list));
    l->next = NULL;
    l->e = e;
    list *cur = n->list;
    while(cur->next) cur = cur->next;
    cur->next = l;
}

node* getAnotherNode(node *n, edge *e) {
    if(e->a == n) return e->b;
    return e->a;
}
/********** Graph ***********/

/********** Prioirity Queue ***********/
typedef struct pqNode {
    int nodeNum, cost;
} pqNode;

typedef struct priority_queue {
    pqNode *heap;
    int size;
} priority_queue;

void swap(pqNode *a, pqNode *b) {
    pqNode tmp = *a;
    *a = *b;
    *b = tmp;
}

void pqInsert(priority_queue *pq, int nodeNum, int cost) {
    pq->size++;
    pq->heap[pq->size].nodeNum=nodeNum;
    pq->heap[pq->size].cost=cost;

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

typedef struct pair {
    int nodeNum, cost;
} pair;

pair pop(priority_queue *pq) {
    pair p = {pq->heap[1].nodeNum, pq->heap[1].cost};
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
    return p;
}
/********** Prioirity Queue ***********/

void freeList(list *l) {
    if(l->next) freeList(l->next);
    free(l);
}

int main(void) {
    int N, M; scanf("%d %d", &N, &M);
    node *n = (node*)malloc(sizeof(node)*N);
    edge *e = (edge*)malloc(sizeof(edge)*M);
    for(int i=0;i<N;i++) {
        n[i].list = (list*)malloc(sizeof(list));
        n[i].list->next = NULL;
        n[i].nodeNum=i;
        n[i].toCost=INF;
    }

    for(int i=0;i<M;i++) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        e[i].a = &n[a-1];
        e[i].b = &n[b-1];
        e[i].cost = c;
        insert(&n[a-1], &e[i]);
        insert(&n[b-1], &e[i]);
    }

    // Priority_Queue Init
    priority_queue *pq = (priority_queue*)malloc(sizeof(priority_queue));
    pq->heap = (pqNode*)malloc(sizeof(pqNode)*100000);
    pq->size=0;

    // Prim-Jarnik
    int sum=0;
    pqInsert(pq, 0, 0);
    while(pq->size) {
        pair cur = pop(pq);
        if(n[cur.nodeNum].toCost!=INF) continue;
        n[cur.nodeNum].toCost=cur.cost;
        printf(" %d", cur.nodeNum+1);
        sum += cur.cost;

        list *l = n[cur.nodeNum].list;
        while(l->next) {
            l = l->next;
            node *next = getAnotherNode(&n[cur.nodeNum], l->e);
            if(next->toCost==INF) {
                pqInsert(pq, next->nodeNum, l->e->cost);
            }
        }
    }
    printf("\n%d", sum);

    // Free
    free(pq->heap);
    free(pq);
    free(e);
    for(int i=0;i<N;i++) freeList(n[i].list);
    free(n);
}