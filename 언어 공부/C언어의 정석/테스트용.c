#include<stdio.h>

int main(void){
	int M,N;
	scanf("%d%d",&M,&N);
	
	for(M;M<=N;M++){
		
		for(int i=2;i<M;i++)
			if(M%i==0) continue;
			
		printf("%d\n",M);
	}
	
	return 0;
}
