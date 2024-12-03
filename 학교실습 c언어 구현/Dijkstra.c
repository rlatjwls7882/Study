#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#define INF 0x3f3f3f3f

/* list */
typedef struct list {
    struct list *next;
    struct edge *e;
} list;

typedef struct node {
    int nodeNum, totalCost;
    list *l;
} node;

typedef struct edge {
    node *a, *b;
    int cost;
} edge;

void insertEdge(node *n, edge *e) {
    list *newList = (list*)malloc(sizeof(list));
    newList->next=NULL;
    newList->e = e;

    list *cur = n->l;
    while(cur->next) cur = cur->next;
    cur->next = newList;
}

node* getAnotherNode(edge *e, int nodeNum) {
    if(e->a->nodeNum==nodeNum) return e->b;
    else return e->a;
}
/* list */

/* Priority Queue */
typedef struct pqNode {
    int nodeNum, cost;
} pqNode;

typedef struct priority_queue {
    pqNode n[100001];
    int size;
} priority_queue;

void swap(pqNode *a, pqNode *b) {
    pqNode tmp = *a;
    *a = *b;
    *b = tmp;
}

void push(priority_queue *pq, int nodeNum, int cost) {
    int idx=++pq->size;
    pq->n[idx].nodeNum = nodeNum;
    pq->n[idx].cost = cost;

    while(idx>1) {
        if(pq->n[idx/2].cost>pq->n[idx].cost) {
            swap(&pq->n[idx/2], &pq->n[idx]);
            idx/=2;
        } else {
            break;
        }
    }
}

pqNode pop(priority_queue *pq) {
    swap(&pq->n[1], &pq->n[pq->size]);
    pq->size--;

    int idx=1;
    while(idx<=pq->size) {
        if(idx*2+1<=pq->size && pq->n[idx*2+1].cost<pq->n[idx*2].cost && pq->n[idx].cost<pq->n[idx*2+1].cost) {
            swap(&pq->n[idx], &pq->n[idx*2+1]);
            idx = idx*2+1;
        } else if(idx*2<=pq->size && pq->n[idx].cost<pq->n[idx*2].cost) {
            swap(&pq->n[idx], &pq->n[idx*2]);
            idx = idx*2;
        } else {
            break;
        }
    }
    return pq->n[pq->size+1];
}
/* Priority Queue */

/* free */
void freeList(list *l) {
    if(l->next) freeList(l->next);
    free(l);
}
/* free */

int main(void) {
    int N, M, S; scanf("%d%d%d", &N, &M, &S);
    node *n = (node*)malloc(sizeof(node)*N);
    edge *e = (edge*)malloc(sizeof(edge)*M);

    for(int i=0;i<N;i++) {
        n[i].nodeNum=i;
        n[i].totalCost = INF;
        n[i].l = (list*)malloc(sizeof(list));
        n[i].l->next=NULL;
    }

    for(int i=0;i<M;i++) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        e[i].a = &n[u-1];
        e[i].b = &n[v-1];
        e[i].cost = w;
        insertEdge(e[i].a, &e[i]);
        insertEdge(e[i].b, &e[i]);
    }

    priority_queue *pq = (priority_queue*)malloc(sizeof(priority_queue));
    pq->size=0;
    push(pq, S-1, 0);
    while(pq->size) {
        pqNode top = pop(pq);
        if(top.cost>=n[top.nodeNum].totalCost) continue;
        n[top.nodeNum].totalCost = top.cost;

        list *next = n[top.nodeNum].l;
        while(next->next) {
            push(pq, getAnotherNode(next->next->e, top.nodeNum)->nodeNum, top.cost+next->next->e->cost);
            next = next->next;
        }
    }

    for(int i=0;i<N;i++) {
        if(i!=S-1 && n[i].totalCost!=INF) printf("%d %d\n", i+1, n[i].totalCost);
    }

    // free
    for(int i=0;i<N;i++) freeList(n[i].l);
    free(n);
    free(e);
    free(pq);
}
/*
Input
5 7 1
1 2 1
1 4 5
5 1 10
3 5 3
4 3 1
3 1 2
2 3 2

Output
2 1
3 2
4 3
5 5

*/