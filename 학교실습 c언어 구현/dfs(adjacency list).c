#include<stdio.h>
#include<stdlib.h>

typedef struct list {
    struct list* next;
    struct edge* connectedEdge;
} list;

typedef struct node {
    list *adj;
    int val, visited;
} node;

typedef struct edge {
    node *node1, *node2;
} edge;

int getNextNodeNum(edge *e, int from) {
    if(e->node1->val==from) return e->node2->val;
    return e->node1->val;
}

node* getNextNode(node *n, list* cur) {
    if(cur->connectedEdge->node1==n) return cur->connectedEdge->node2;
    return cur->connectedEdge->node1;
}

void connect(node *n, edge *e, int to) {
    list *newNode = (list*)malloc(sizeof(list));
    newNode->next=NULL;
    newNode->connectedEdge = e;

    list *cur = n->adj;
    if(cur->next==NULL) {
        cur->next = newNode;
    } else {
        while(cur->next!=NULL && getNextNodeNum(cur->next->connectedEdge, n->val)<to) cur = cur->next;
        if(cur->next) newNode->next = cur->next;
        cur->next = newNode;
    }
}

void dfs(node *n) {
    if(n->visited) return;
    n->visited = 1;
    printf("%d\n", n->val);
    list *cur = n->adj;

    while(cur->next) {
        dfs(getNextNode(n, cur->next));
        cur = cur->next;
    }
}

void freeList(list *cur) {
    if(cur->next) freeList(cur->next);
    free(cur);
}

int main(void) {
    int N, M, S; scanf("%d %d %d", &N, &M, &S);
    node *n = (node*)malloc(sizeof(node)*N);
    edge *e = (edge*)malloc(sizeof(edge)*M);

    for(int i=0;i<N;i++) {
        n[i].adj = (list*)malloc(sizeof(list));
        n[i].adj->next=NULL;
        n[i].val = i+1;
        n[i].visited = 0;
    }

    for(int i=0;i<M;i++) {
        int a, b; scanf("%d %d", &a, &b);
        e[i].node1 = &n[a-1];
        e[i].node2 = &n[b-1];
        connect(&n[a-1], &e[i], b);
        connect(&n[b-1], &e[i], a);
    }

    dfs(&n[S-1]);

    for(int i=0;i<N;i++) freeList(n[i].adj);
    free(n);
    free(e);
}