#include<stdio.h>
int main(){
	int N,M,O;
	scanf("%d",&N);
	
	for(int i=1;i<=N;i++){
		M=N-i;
		for(M;M>0;M--) printf(" ");
		
		O=i;
		for(O;O>0;O--) printf("*");
		printf("\n");
	}
}