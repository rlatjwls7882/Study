#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#define INF 0x3f3f3f3f

/* Graph */
typedef struct node {
    int nodeNum, totalCost;
} node;

typedef struct edge {
    node *a, *b;
    int cost;
} edge;
/* Graph */

int BellmanFord(node *n, edge *e, int N, int M) {
    for(int i=0;i<N;i++) {
        int change=0;
        for(int j=0;j<M;j++) {
            if(e[j].a->totalCost!=INF && e[j].b->totalCost > e[j].a->totalCost+e[j].cost) {
                e[j].b->totalCost = e[j].a->totalCost+e[j].cost;
                change=1;
            }
        }
        if(!change) break;
        if(i==N-1 && change) return 1;
    }
    return 0;
}

int main(void) {
    int N, M, S; scanf("%d%d%d", &N, &M, &S);
    node *n = (node*)malloc(sizeof(node)*N);
    edge *e = (edge*)malloc(sizeof(edge)*M);

    for(int i=0;i<N;i++) {
        n[i].nodeNum=i;
        n[i].totalCost = INF;
    }

    for(int i=0;i<M;i++) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        e[i].a = &n[u-1];
        e[i].b = &n[v-1];
        e[i].cost = w;
    }

    n[S-1].totalCost=0;
    int ret = BellmanFord(n, e, N, M);

    if(ret) {
        printf("cycle!");
    } else {
        for(int i=0;i<N;i++) {
            if(i!=S-1 && n[i].totalCost!=INF) printf("%d %d\n", i+1, n[i].totalCost);
        }
    }

    // free
    free(n);
    free(e);
}
/*
Input1
5 7 1
1 2 1
1 4 5
5 1 -2
3 5 3
3 4 1
1 3 2
3 2 -3

Output1
2 –1
3 2
4 3
5 5

Input2
4 5 1
1 2 1
2 3 -2
3 1 2
3 4 1
1 4 5

Ouput2
2 1
3 –1
4 0

*/