#include<stdio.h>
int main(){
	int N,tmp;
	scanf("%d",&N);
	for(int i=N;i>=1;i--) {
		tmp = i;
		for(int j=1;j<=N-i;j++) printf(" ");
		while(tmp--) printf("*");
		printf("\n");
	}
} 