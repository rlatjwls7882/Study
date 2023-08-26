#include<stdio.h>
int main(){
	int N,tmp;
	scanf("%d",&N);
	for(int i=N;i>0;i--) {
		tmp = i*2-1;
		
		for(int j=N;j>i;j--) printf(" ");
		
		while(tmp--) printf("*");
		
		printf("\n");
	}
	for(int i=2;i<=N;i++) {
		tmp = i*2-1;
		
		for(int j=i;j<N;j++) printf(" ");
		
		while(tmp--) printf("*");
		
		printf("\n");
	}
}