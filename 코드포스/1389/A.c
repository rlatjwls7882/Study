#include<stdio.h>

int main(void) {
    int t; scanf("%d", &t);

    while(t-->0) {
        int l, r; scanf("%d %d", &l, &r);
        if(l*2<=r) {
            printf("%d %d\n", l, l*2);
        } else {
            printf("-1 -1\n");
        }
    }
}