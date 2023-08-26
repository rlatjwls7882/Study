#include<stdio.h>
int main(){
	int N,tmp;
	scanf("%d",&N);
	for(int i=1;i<=N;i++) {
		tmp = 2*i-1;
		for(int j=1;j<=N-i;j++) printf(" ");
		while(tmp--) printf("*");
		printf("\n");
	}
}