#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

// DAG
typedef struct list {
    struct list *next;
    struct edge* e;
} list;

typedef struct node {
    char val;
    int nodeNum;
    list *conn;
} node;

typedef struct edge {
    node *a, *b;
} edge;


// Queue
typedef struct Qlist {
    struct Qlist *prev, *next;
    node* n;
} Qlist;

typedef struct queue {
    Qlist *front, *back;
    int empty;
} queue;

// graph input
void insert(node *n, edge *e) {
    list *l = (list*)malloc(sizeof(list));
    l->next=n->conn->next;
    l->e=e;
    n->conn->next = l;
}

// free
void freeList(list *l) {
    if(l->next) freeList(l->next);
    free(l);
}

void freeQList(Qlist *l) {
    if(l->next) freeQList(l->next);
    free(l);
}

// init Queue
void initQ(queue *q) {
    q->front = NULL;
    q->back = NULL;
    q->empty=1;
}

// push item in queue
void push(queue *q, node *n) {
    Qlist *l = (Qlist*)malloc(sizeof(Qlist));
    l->prev = l->next = NULL;
    l->n = n;
    if(q->empty) {
        q->back = q->front = l;
    } else {
        q->back->next = l;
        l->prev = q->back;
        q->back = l;
    }
    q->empty=0;
}

// pop item in queue
void pop(queue *q) {
    q->front = q->front->next;
    if(q->front == NULL) q->empty=1;
    else q->front->prev=NULL;
}

void topological_sort(int N, node *n, int *inDegree) {
    // sort
    char *res = (char*)malloc(sizeof(char)*N);
    int resIdx=0;
    queue *q = (queue*)malloc(sizeof(queue));
    initQ(q);
    for(int i=0;i<N;i++) if(!inDegree[i]) push(q, &n[i]);
    while(!q->empty) {
        node *top = q->front->n; pop(q);
        list *cur = top->conn;
        while(cur->next) {
            cur = cur->next;
            node *next = cur->e->b;
            if(--inDegree[next->nodeNum]==0) {
                push(q, next);
            }
        }
        res[resIdx++] = top->val;
    }

    // print
    if(resIdx==N) for(int i=0;i<resIdx;i++) printf("%c ", res[i]);
    else printf("0");

    // free
    free(res);
    if(q->front) freeQList(q->front);
    free(q);
}

int main(void) {
    int N; scanf("%d", &N);
    int *charToIdx = (int*)malloc(sizeof(int)*128);
    for(int i=0;i<128;i++) charToIdx[i] = NULL;
    int *inDegree = (int*)malloc(sizeof(int)*N);
    for(int i=0;i<N;i++) inDegree[i]=0;

    // input node
    node *n = (node*)malloc(sizeof(node)*N);
    for(int i=0;i<N;i++) {
        scanf(" %c", &n[i].val);
        charToIdx[n[i].val]=i;
        n[i].nodeNum=i;
        n[i].conn = (list*)malloc(sizeof(list));
        n[i].conn->next = NULL;
    }

    // input edge
    int M; scanf("%d", &M);
    edge *e = (edge*)malloc(sizeof(edge)*M);
    for(int i=0;i<M;i++) {
        char a, b; scanf(" %c %c", &a, &b);
        e[i].a = &n[charToIdx[a]];
        e[i].b = &n[charToIdx[b]];
        insert(e[i].a, &e[i]);
        inDegree[charToIdx[b]]++;
    }

    // sort
    topological_sort(N, n, inDegree);

    // free
    free(inDegree);
    free(charToIdx);
    for(int i=0;i<N;i++) if(n[i].conn->next) freeList(n[i].conn);
    free(n);
    free(e);
}